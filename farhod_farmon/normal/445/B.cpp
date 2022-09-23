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

const int N = 55;

using namespace std;

lli n, d[N], ans, m, cnt, k;
vector < lli > v[N];
bool used[N];

void dfs( lli x )
{
    if( used[x] )
        return;
    used[x] = true;
    cnt++;
    for( lli i = 0; i < v[x].size(); i++ )
        dfs(v[x][i]);
}

int main()
{
    cin >> n >> m;
    for( lli i = 1; i <= m; i++ ){
        lli x, y;
        cin >> x >> y;
        v[y].pb(x);
        v[x].pb(y);
    }
    for( lli i = 1; i <= n; i++ ){
        if( !used[i] ){
            cnt = 0;
            dfs(i);
            ans += cnt;
            k++;
        }
    }
    cnt = 1;
    for( lli i = 1; i <= ans - k; i++ )
        cnt *= 2ll;
    cout << cnt << endl;
}