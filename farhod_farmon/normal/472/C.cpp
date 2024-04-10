#include <iostream>
using namespace std;
int main()
{
    int a,b[100001],c,d,e,f,g,i,j;
    cin>>a;
    string s[a+1],t[a+1],x,y;
    for( i=1; i<=a; i++ ){
         cin>>s[i]>>t[i];
         x=s[i];
         y=t[i];
         s[i]=min( x, y );
         t[i]=max( x, y );
    }
    for( i=1; i<=a; i++ ) cin>>b[i];
    x=s[b[1]];
    for( i=2; i<=a; i++ ){
         if( s[b[i]]>=x ){
             x=s[b[i]];    
         }
         else if( t[b[i]]>=x ){
              x=t[b[i]];     
         }
         else{
              cout<<"NO";
              return 0;
         }     
    }
    cout<<"YES";
    return 0;
}