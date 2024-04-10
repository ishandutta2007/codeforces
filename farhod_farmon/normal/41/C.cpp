#include <iostream>
using namespace std;
int main()
{
    string s,t;
    int i,a=0;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
         if( s[i]=='a' && s[i+1]=='t' && a==0 && i>0 && i+2<s.size() ){
             t+='@';
             i+=1;
             a=1;
         }     
         else if( s[i]=='d' && s[i+1]=='o' && s[i+2]=='t' && i>0 && i+3<s.size() ){
             t+='.';
             i+=2;
         }     
         else{
             t+=s[i];     
         }
    } 
    cout<<t;
    return 0;
}