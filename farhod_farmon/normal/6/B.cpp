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
    map < char, int > m;
    int a,b,i,j,h,cnt=0;
    char c[102][102],s;
    cin>>a>>b>>s;
    for( i=1; i<=a; i++ ){
         for( j=1; j<=b; j++ ){
              cin>>c[i][j];
              m[c[i][j]]=0;
         }     
    }
    for( i=1; i<=a; i++ ){
         for( j=1; j<=b; j++ ){
              if( c[i][j]==s ){
                  m[c[i+1][j]]=m[c[i-1][j]]=m[c[i][j+1]]=m[c[i][j-1]]=1;     
              }
         }     
    }
    m['.']=0;
    m[s]=0;
    for( i=1; i<=a; i++ ){
         for( j=1; j<=b; j++ ){
              cnt=cnt+m[c[i][j]];
              m[c[i][j]]=0;     
         }     
    }
    cout<<cnt;
    //system( "pause" );
    return 0;
}