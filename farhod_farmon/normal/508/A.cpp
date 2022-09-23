#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define max( a, b, c ) max( a, max( b, c ) )
#define max( a, b, c, d ) max( max( a, b ), max( c, d ) )

using namespace std;
int main()
{
    char d[1002][1002];
    int a,b,c,i,j,cnt=0,h,k,x[100001],y[100001];
    cin>>a>>b>>c;
    for( i=1; i<=c; i++ ){
         cin>>x[i]>>y[i];
    }
    for( i=0; i<=1001; i++ ){
         for( j=0; j<=1001; j++ ){
              d[i][j]='0';     
         }     
    }
    for( i=1; i<=c; i++ ){
         d[x[i]][y[i]]='1';
         if( (d[x[i]][y[i]+1]=='1' && d[x[i]+1][y[i]]=='1' && d[x[i]+1][y[i]+1]=='1') || (d[x[i]][y[i]-1]=='1' && d[x[i]+1][y[i]-1]=='1' && d[x[i]+1][y[i]]=='1') || (d[x[i]-1][y[i]]=='1' && d[x[i]-1][y[i]+1]=='1' && d[x[i]][y[i]+1]=='1') || (d[x[i]][y[i]-1]=='1' && d[x[i]-1][y[i]-1]=='1' && d[x[i]-1][y[i]]=='1') ){
             cout<<i;
             //system("pause");
             return 0;    
         }     
    }
    cout<<0;
    //system ( "pause" );
    return 0;    
}