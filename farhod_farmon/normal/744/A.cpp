#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n, m, k;
bool f[N];
bool used[N];
bool edge[N][N];
vector < int > v[N], g;
vector < vector < int > > comp;

void dfs(int x)
{
    if(used[x])
        return;
    used[x] = true;
    g.pb(x);
    for(auto y: v[x])
        dfs(y);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        f[x] = true;
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
        edge[x][y] = edge[y][x] = true;
    }
    long long mx = 0;
    for(int i = 1; i <= n; i++){
        if(used[i])
            continue;
        g.clear();
        dfs(i);
        comp.pb(g);
        bool b = false;
        for(int j = 0; j < g.size(); j++)
            if(f[g[j]])
                b = true;
        if(b)
            mx = max(mx, (long long)g.size());
    }
    long long ans = 0;
    vector < int > g;
    for(int i = 0; i < comp.size(); i++){
        g = comp[i];
        bool b = false;
        long long cnt = g.size() * (g.size() - 1) / 2;
        for(int j = 0; j < g.size(); j++){
            for(int h = j + 1; h < g.size(); h++)
                if(edge[g[j]][g[h]])
                    cnt--;
            if(f[g[j]])
                b = true;
        }
        ans += cnt;
        if(!b){
            ans += g.size() * mx;
            mx += g.size();
        }
    }
    cout << ans << endl;
}