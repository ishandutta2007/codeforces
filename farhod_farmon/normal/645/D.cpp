#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100001;

using namespace std;

vector < int > v[N], g;
int n, m, ps[N], cnt;
bool used[N];

void dfs( int x )
{
    if( used[x] )
        return;
    used[x] = true;
    for( int i = 0; i < v[x].size(); i++ )
        dfs(v[x][i]);
    g.pb(x);
}

int main()
{
    int i, x[N], y[N];
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x[i] >> y[i];
        v[x[i]].pb(y[i]);
    }
    for( i = 1; i <= n; i++ )
        dfs(i);
    for( i = 0; i < n; i++ )
        ps[g[i]] = i;
    for( i = 1; i <= m; i++ ){
        if( used[y[i]] && ps[y[i]] + 1 == ps[x[i]] ){
            used[y[i]] = false;
            cnt++;
        }
        if( cnt == n - 1 ){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}