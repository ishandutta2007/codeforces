#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, m;
vector < pair < int, char > > v[100001];
vector < int > f[3];
int used[100001];

bool dfs( int x, int y, char c )
{
    if( used[x] ){
        if( used[x] != y )
            return false;
        return true;
    }
    used[x] = y;
    f[y].pb(x);
    for( int i = 0; i < v[x].size(); i++ )
        if( !dfs(v[x][i].fi, (v[x][i].se == c ? y : 3 - y), c) )
            return false;
    return true;
}

vector < int > solve( char c )
{
    vector < int > ff;
    for( int i = 1; i <= n; i++ )
        used[i] = 0;
    for( int i = 1; i <= n; i++ ){
        if( !used[i] ){
            f[1].clear();
            f[2].clear();
            if( !dfs(i, 1, c) ){
                for( int i = 1; i <= n + 1; i++ )
                    ff.pb(0);
                break;
            }
            if( f[2].size() < f[1].size() )
                for( int i = 0; i < f[2].size(); i++ )
                    ff.pb(f[2][i]);
            else
                for( int i = 0; i < f[1].size(); i++ )
                    ff.pb(f[1][i]);
        }
    }
    return ff;
}

int main()
{
    int x, y;
    char c;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ){
        cin >> x >> y >> c;
        v[x].pb(mp(y, c));
        v[y].pb(mp(x, c));
    }

    vector < int > g = solve('R');
    vector < int > g1 = solve('B');
    if( g1.size() < g.size() )
        swap(g, g1);
    if( g.size() > n ){
        cout << -1 << endl;
        return 0;
    }
    cout << g.size() << endl;
    for( int i = 0; i < g.size(); i++ )
        cout << g[i] << " ";
}