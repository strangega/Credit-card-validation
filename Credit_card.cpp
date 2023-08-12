#include<bits/stdc++.h>
using namespace std;
int getdigit(int k){
    if(k>9)
        return (k%10)+1;
    return k;    
}
int getsize(long num){
    string numb=to_string(num);
    return numb.size();
}
int getprefix(long num,int l){
    string numb=to_string(num);
    return stol(numb.substr(0,l));
}
bool prefixmatch(long num,int k){
   
    return (getprefix(num,getsize(k))==k);
}
int sum( long int number )  
{  
    int sum = 0;  
    string num = to_string(number);  
    for (long i = getsize( number )-2;i>=0;i-=2)  
        sum += getdigit(int( num[i]-'0')*2); 
    for(int i=getsize(number)-1;i>=0;i-=2)
        sum+=int(num[i]-'0');
    return sum;  
}
bool isvalid(long num){
    return (getsize(num)>12 && getsize(num)<17 && (prefixmatch(num,4) ||prefixmatch(num,5) || prefixmatch(num,37) ||prefixmatch(num,6)) && 
   sum(num)%10==0);
}
int main(){
    long long number;
    cin>>number;
    cout<<sum(number)<<endl;
    cout<<"the credit card number is "<<((isvalid(number))? "valid":"not valid");
    return 0;
}
