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
#include <iomanip>

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

using namespace std;

struct ILYOU
{
    int n, s, w, e;
};

ILYOU d[1001][1001];
int n, m, k;
char c[1001][1001];
bool b1;
vector < char > v;
pair < char, int > p[100001];

pair < bool, pair < int, int > > istrue( int x, int y, pair < char, int > l )
{
    pair < bool, pair < int, int > > take;
    if( l.fi == 'S' ){
        take.fi = (x + l.se < d[x][y].s);
        take.se = mp(x + l.se, y);
    }
    if( l.fi == 'N' ){
        take.fi = (x - l.se > d[x][y].n);
        take.se = mp(x - l.se, y);
    }
    if( l.fi == 'E' ){
        take.fi = (y + l.se < d[x][y].e);
        take.se = mp(x, y + l.se);
    }
    if( l.fi == 'W' ){
        take.fi = (y - l.se > d[x][y].w);
        take.se = mp(x, y - l.se);
    }
    return take;
}

void dfs( int x, int y, int g = 1 )
{
    if( g == k + 1 )return;
    pair < bool, pair < int, int > > take = istrue(x, y, p[g]);
    if( !take.fi ){
        b1 = false;
        return;
    }
    dfs( take.se.fi, take.se.se, g + 1 );
}

int main()
{
    int i, j, h;
    cin >> n >> m;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c[i][j];
            if( c[i][j] == '#' ){
                d[i][j].n = i;
                d[i][j].w = j;
            }
            else{
                d[i][j].n = d[i - 1][j].n;
                d[i][j].w = d[i][j - 1].w;
            }
        }
    }
    for( i = n; i >= 1; i-- ){
        for( j = m; j >= 1; j-- ){
            if( c[i][j] == '#' ){
                d[i][j].s = i;
                d[i][j].e = j;
            }
            else{
                d[i][j].s = d[i + 1][j].s;
                d[i][j].e = d[i][j + 1].e;
            }
        }
    }
    cin >> k;
    for( i = 1; i <= k; i++ )cin >> p[i].fi >> p[i].se;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( 'A' <= c[i][j] && c[i][j] <= 'Z' ){
                b1 = true;
                dfs(i, j);
                if( b1 )v.pb(c[i][j]);
            }
        }
    }
    if( !v.size() ){
        cout << "no solution" << endl;
        return 0;
    }
    sort( v.begin(), v.end() );
    for( i = 0; i < v.size(); i++ )cout << v[i];
}