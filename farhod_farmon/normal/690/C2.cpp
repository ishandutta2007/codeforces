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

const int N = 100001;

using namespace std;

vector < int > v[N];
int n, m, down[N], up[N], ans;

void dfs(int x, int p)
{
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] == p)
            continue;
        dfs(v[x][i], x);
        down[x] = max(down[x], down[v[x][i]] + 1);
    }
}

void trace(int x, int p)
{
    int h[2] = {0}, mx[2] = {0};
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] == p)
            continue;
        if(down[v[x][i]] + 1 > mx[0]){
            mx[1] = mx[0];
            mx[0] = down[v[x][i]] + 1;
            h[1] = h[0];
            h[0] = v[x][i];
        }
        else if(down[v[x][i]] + 1 > mx[1]){
            mx[1] = down[v[x][i]] + 1;
            h[1] = v[x][i];
        }
    }
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] == p)
            continue;
        if(v[x][i] == h[0])
            up[v[x][i]] = max(up[x], mx[1]) + 1;
        else
            up[v[x][i]] = max(up[x], mx[0]) + 1;
        trace(v[x][i], x);
    }
    ans = max(ans, up[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, -1);
    trace(1, -1);
    cout << ans << endl;
    return 0;
}