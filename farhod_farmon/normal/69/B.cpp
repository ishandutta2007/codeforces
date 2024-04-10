#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a,m,l[101],r[101],t[101],c[101],i,j,b[101]={},cnt=0,d[101]={};
    cin>>a>>m;
    for( i=1; i<=m; i++ ){
         cin>>l[i]>>r[i]>>t[i]>>c[i];     
    }
    for( i=1; i<=m; i++ ){
         for( j=l[i]; j<=r[i]; j++ ){
              if( t[i]<d[j] ){
                  b[j]=c[i];
                  d[j]=t[i];    
              }
              else if( d[j]==0 ){
                   b[j]=c[i];
                   d[j]=t[i];     
              }
         }     
    }
    for( i=1; i<=a; i++ )cnt+=b[i];
    cout<<cnt; 
    return 0;
}