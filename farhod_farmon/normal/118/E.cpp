#include <bits/stdc++.h>

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

const int N = 100001;

using namespace std;

int n, m, tin[N], f[N], tim;
vector < int > v[N];
vector < pair < int, int > > ans;
bool used[N];

void dfs( int x, int p = -1 )
{
    used[x] = true;
    tin[x] = f[x] = tim++;
    for( int i = 0; i < v[x].size(); i++ ){
        int to = v[x][i];
        if( to == p )continue;
        if( used[to] ){
            f[x] = min(f[x], tin[to]);
            if( tin[x] > tin[to] )ans.pb(mp(x, to));
        }
        else{
            dfs(to, x);
            f[x] = min(f[x], f[to]);
            if( f[to] > tin[x] ){
                cout << "0" << endl;
                exit(0);
            }
            ans.pb(mp(x, to));
        }
    }
}

int main()
{
    int i, j, h, x, y;
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    for( i = 0; i < m; i++ )cout << ans[i].fi << " " << ans[i].se << endl;
}