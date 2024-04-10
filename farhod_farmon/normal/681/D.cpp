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

const int N = 100100;

using namespace std;

vector < int > v[N], ans;
int a[N], n, m, b[N], tin[N], tout[N];
bool used[N], p[N];

bool par(int x, int y)
{
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    for(int i = 0; i < v[x].size(); i++){
        int y = v[x][i];
        dfs(y);
        if(a[x] != a[y] && par(a[y], x)){
            cout << -1 << endl;
            exit(0);
        }
    }
    if(a[x] == x)
        ans.pb(x);
}

int tim;

void tr(int x)
{
    tin[x] = ++tim;
    for(int i = 0; i < v[x].size(); i++)
        tr(v[x][i]);
    tout[x] = ++tim;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        p[y] = true;
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        if(!p[i])
            tr(i);
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs(i);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}