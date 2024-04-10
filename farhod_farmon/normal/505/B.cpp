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
vector < int > rang[101][101],v[101],ans;
int a,b,q,az,to,cnt;
bool used[101][101],used1[101];

void dfs( int y, int z )
{
    if( used[y][z] || used1[z] )return;
    if( y==to ){
        cnt++;
        used1[z]=1;
        return;
    }
    used[y][z]=1;
    for( int i=0; i<v[y].size(); i++ ){
        for( int j=0; j<rang[y][v[y][i]].size(); j++ ){
            if( z==rang[y][v[y][i]][j] || z==0 ){
                dfs( v[y][i], rang[y][v[y][i]][j] );
            }
        }
    }
}

int main()
{
    cin>>a>>b;
    for( int i=1; i<=b; i++ ){
        int x,y,c;
        cin>>x>>y>>c;
        if( rang[x][y].size()==0 ){
            v[x].pb(y);
            v[y].pb(x);
        }
        rang[x][y].pb(c);
        rang[y][x].pb(c);
    }
    cin>>q;
    for( int i1=1; i1<=q; i1++ ){
        cin>>az>>to;
        cnt=0;
        for( int h1=1; h1<=100; h1++ ) for( int h2=0; h2<=100; h2++ ) used[h1][h2]=used1[h1]=0;
        dfs( az, 0 );
        ans.pb(cnt);
    }
    for( int i=0; i<ans.size(); i++ ) cout<<ans[i]<<endl;
    return 0;
}