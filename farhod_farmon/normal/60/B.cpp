#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define lli long long int
#define pr printf
#define sc scanf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define rep( a, b ) for( int i=a; i<=b; i++ )
#define tochniy_rep( a, b ) for( int i=min( a, b ); i<=max( a, b ); i++ )
#define fin freopen( "prefrev.txt", "r", stdin );
#define fout freopen( "prefrev.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int used[12][12][12]={},cnt=0,g=0,g1,g2,a,b,c;
char s[30][30][30];

void rec( int k, int x, int y )
{
    if( s[k][x][y]=='.' && !used[k][x][y] ){
        cnt++;
    }
    if( used[k][x][y] )return;
    used[k][x][y]=1;
    int g=k-1;
    while( s[g][x][y]=='.' &&  g>=1 ){
        rec( g, x, y );
        g--;
    }
    g=k+1;
    while( s[g][x][y]=='.' &&  g<=a ){
        rec( g, x, y );
        g++;
    }
    if( s[k][x+1][y]=='.' )rec( k, x+1, y );
    if( s[k][x-1][y]=='.' )rec( k, x-1, y );
    if( s[k][x][y+1]=='.' )rec( k, x, y+1 );
    if( s[k][x][y-1]=='.' )rec( k, x, y-1 );
}

int main()
{
    int i,j,h,k,l,n,m,x,y;
    cin>>a>>b>>c;
    for( i=0; i<=15; i++ ){
        for( j=0; j<=15; j++ ){
            for( h=0; h<=15; h++ ){
                s[i][j][h]='#';
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            for( h=1; h<=c; h++ ){
                cin>>s[i][j][h];
                used[i][j][h]=0;
            }
        }
    }
    cin>>x>>y;
    rec ( 1, x, y );
    cout<<cnt;
    return 0;
}