#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a,b,d[101],e,f,g,h,i,j,k,cnt=0,ans=0;
int c;

int main()
{
    for( i=0; i<=100; i++ )d[i]=1; 
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b>>c;
         if( i==1 ){
             e=b;
             f=c;    
         }
         else{
              for( j=b; j<c; j++ ){
                   d[j]=0;
              }         
         } 
    }
    for( i=e; i<f; i++ ){
         cnt+=d[i];
    }
    cout<<cnt;
    //system( "pause" );
    return 0;    
}