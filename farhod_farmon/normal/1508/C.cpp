#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;

int n, m;
int p[N];
vector < int > v[N];
vector < vector < int > > E;
set < int > used;
int comp;
vector < pair < int, int > > vg[N];

void dfs(int x, int col)
{
        p[x] = col;
        //cout << x << " " << col << "\n";
        used.erase(x);
        for(int i = 0; i + 1 < v[x].size(); i++){
                auto p = used.lower_bound(v[x][i] + 1);
                while(p != used.end() && *p < v[x][i + 1]){
                        vg[x].push_back({*p, 1});
                        vg[*p].push_back({x, 1});

                        //cout << x << " -> " << *p << "\n";

                        dfs(*p, col);
                        p = used.lower_bound(v[x][i] + 1);
                }
        }
}

int get_p(int x) { return p[x] == x ? x : p[x] = get_p(p[x]); }

int f[N][20];
int t[N];
int tim;
int tin[N], tout[N];

void dfs1(int x, int p)
{
        tin[x] = ++tim;
        f[x][0] = p;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        for(auto y: vg[x]){
                if(y.fi == p){
                        continue;
                }
                t[y.fi] = t[x] + y.se;
                dfs1(y.fi, x);
        }
        tout[x] = tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        } else if(isp(y, x)){
                return y;
        }
        for(int i = 19; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                E.push_back({w, x, y});
        }

        sort(E.begin(), E.end());

        for(auto& g: E){
                v[g[1]].push_back(g[2]);
                v[g[2]].push_back(g[1]);
        }
        for(int i = 1; i <= n; i++){
                used.insert(i);
                v[i].push_back(0);
                v[i].push_back(n + 1);
                sort(v[i].begin(), v[i].end());
        }

        for(int i = 1; i <= n; i++){
                if(p[i]){
                        continue;
                }
                comp += 1;
                dfs(i, i);
        }

        for(int i = 1; i <= n; i++){
                v[i].clear();
        }

        long long res = 0;
        int X = 0;
        for(auto &g: E){
                X ^= g[0];

                int x = get_p(g[1]), y = get_p(g[2]);
                if(x != y){
                        res += g[0];
                        p[x] = y;
                        vg[g[2]].push_back({g[1], 0});
                        vg[g[1]].push_back({g[2], 0});
                }
        }

        long long rem = 1ll * n * (n - 1) / 2 - m;
        if(rem > n - comp){
                cout << res << "\n";
                return 0;
        }

        dfs1(1, 1);

        for(auto &g: E){
                int x = g[1], y = g[2], p = lca(g[1], g[2]);
                if(t[x] + t[y] - 2 * t[p]){
                        X = min(X, g[0]);
                }
        }

        cout << res + X << "\n";
}