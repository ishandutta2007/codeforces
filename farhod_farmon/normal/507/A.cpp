#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>

#define lli long long int 
#define se second
#define fi first
#define pb push_back

using namespace std;
int main()
{
    int a,b,c[101],d[101],cnt=0,f[101],g=0,h[101],i,j;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
         cin>>c[i];
         d[i]=c[i];     
         f[i]=0;
    }
    sort( d+1, d+a+1 );
    for( i=1; i<=a; i++ ){
         if( b-d[i]>=0 ){
             b-=d[i];
             cnt++;
             for( j=1; j<=a; j++ ){
                  if( d[i]==c[j] && f[j]==0 ){
                      f[j]=1;
                      h[cnt]=j;
                      break;   
                  }     
             }    
         }    
         else{
              break;     
         } 
    }
    cout<<cnt<<endl;
    for( i=1; i<=cnt; i++ ){
         cout<<h[i]<<" "; 
    }
    //system( "pause" );
    return 0;
}