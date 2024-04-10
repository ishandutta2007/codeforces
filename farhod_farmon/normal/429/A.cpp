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

int n;
int a[100001];
int b[100001];
int d[100001][2];
int dep[100001];
vector < int > v[100001], ans;

void dfs( int x, int p )
{
    a[x] ^= d[x][dep[x] % 2];
    if( a[x] != b[x] ){
        ans.pb(x);
        d[x][dep[x] % 2] += 1;
        d[x][dep[x] % 2] %= 2;
    }
    for( int i = 0; i < v[x].size(); i++ ){
        int to = v[x][i];
        if( to == p )
            continue;
        dep[to] = dep[x] + 1;
        d[to][0] = d[x][0];
        d[to][1] = d[x][1];
        dfs(to, x);
    }
}

int main()
{
    int i, j, h, x, y;
    cin >> n;
    for( i = 1; i < n; i++ ){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for( i = 1; i <= n; i++ )
        cin >> a[i];
    for( i = 1; i <= n; i++ )
        cin >> b[i];
    dfs(1, -1);
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )
        cout << ans[i] << endl;
}