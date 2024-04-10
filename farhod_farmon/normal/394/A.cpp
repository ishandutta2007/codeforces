#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int a,b,d[101],e,f,g,h,i,j,k,cnt=1,ans=0;
int c;

int main()
{
    string s;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
         if( s[i]=='+' || s[i]=='=' ){
             cnt++;
             continue;
         }     
         d[cnt]++;
    }
    if( d[1]+d[2]==d[3] )cout<<s;
    else if ( d[1]+1+d[2]==d[3]-1 ){
         for( i=1; i<=d[1]+1; i++ )cout<<'|';
         cout<<'+';
         for( i=1; i<=d[2]; i++ )cout<<'|';
         cout<<'='; 
         for( i=1; i<=d[3]-1; i++ )cout<<'|'; 
    }
    else if ( d[1]+d[2]-1==d[3]+1 ){
         if( d[1]>d[2] )
         {
             for( i=1; i<=d[1]-1; i++ )cout<<'|';
             cout<<'+';
             for( i=1; i<=d[2]; i++ )cout<<'|';
             cout<<'='; 
             for( i=1; i<=d[3]+1; i++ )cout<<'|'; 
         }
         else{
             for( i=1; i<=d[1]; i++ )cout<<'|';
             cout<<'+';
             for( i=1; i<=d[2]-1; i++ )cout<<'|';
             cout<<'='; 
             for( i=1; i<=d[3]+1; i++ )cout<<'|'; 
         }
    }
    else{
         cout<<"Impossible";     
    }
    //394 A
    return 0;    
}