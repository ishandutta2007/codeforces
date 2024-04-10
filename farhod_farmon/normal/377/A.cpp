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
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a,b,k,i,j;
bool used[505][505];
char c[505][505];

void dfs( int x, int y )
{
    if( x<1 || y<1 || x>a || y>b || used[x][y] || c[x][y]=='#' || c[x][y]=='X' )return;
    used[x][y]=1;
    dfs( x-1, y );
    dfs( x+1, y );
    dfs( x, y-1 );
    dfs( x, y+1 );
    if( k>0 ){
        k--;
        c[x][y]='X';
    }
}

int main()
{
    cin>>a>>b>>k;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]=='.' ){
                dfs(i, j);
                for( i=1; i<=a; i++ ){
                    for( j=1; j<=b; j++ ){
                        cout<<c[i][j];
                    }
                    cout<<endl;
                }
                return 0;
            }
        }
    }
    return 0;
}