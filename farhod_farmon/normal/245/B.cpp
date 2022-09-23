#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int a,b,d[101],e,f,g,h,i,j,k,cnt=0,ans=0;
int c;

int main()
{
    string s,t;
    cin>>s;
    if( s[0]=='f' )t+="ftp://";
    else t+="http://";
    for( i=0; i<s.size(); i++ ){
         if( s[i]=='p' )break;     
    }
    i++;
    ans=i;
    for( ; i<s.size(); i++ ){
         if( s[i]=='r' && s[i+1]=='u' && cnt==0 && i>ans ){
             t+=".ru";
             i+=2;
             cnt=1;
         }   
         if( i<s.size() && cnt==1 ){
             t+="/";
             cnt=2;    
         }
         if( i<s.size() )t+=s[i];
    }
    cout<<t;
    return 0;    
}