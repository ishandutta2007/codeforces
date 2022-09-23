#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int dip[N];
int ans[N];
int f[N][19];
bool used[N];
long long d[N];
vector < int > v[N], g[N], ord;
vector < pair < int, int > > e[N];

void djk(int x)
{
        for(int i = 1; i <= n; i++){
                d[i] = 1e18;
        }
        set < pair < long long, int > > s;
        d[x] = 0;
        s.insert({0, x});
        while(!s.empty()){
                x = s.begin()->se;
                s.erase(s.begin());
                for(auto p: e[x]){
                        int y = p.fi;
                        long long w = p.se;
                        if(d[x] + w < d[y]){
                                s.erase({d[y], y});
                                d[y] = d[x] + w;
                                s.insert({d[y], y});
                        }
                }
        }
}

void dfs(int x, int p)
{
        used[x] = 1;
        for(int y: v[x]){
                if(used[y]){
                        continue;
                }
                dfs(y, x);
        }
        ord.push_back(x);
}

void add(int x, int p)
{
        f[x][0] = p;
        for(int i = 1; i < 19; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        dip[x] = dip[p] + 1;
}

int lift(int x, int g)
{
        for(int i = 0; i < 19; i++){
                if(g & (1 << i)){
                        x = f[x][i];
                }
        }
        return x;
}

int lca(int x, int y)
{
        if(dip[x] > dip[y]){
                x = lift(x, dip[x] - dip[y]);
        }
        if(dip[y] > dip[x]){
                y = lift(y, dip[y] - dip[x]);
        }
        if(x == y){
                return x;
        }
        for(int i = 18; i >= 0; i--){
                if(f[x][i] != f[y][i]){
                        x = f[x][i];
                        y = f[y][i];
                }
        }
        return f[x][0];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int s;
        cin >> n >> m >> s;
        for(int i = 1; i <= m; i++){
                int x, y;
                long long w;
                cin >> x >> y >> w;
                e[x].push_back({y, w});
                e[y].push_back({x, w});
        }
        djk(s);
        for(int i = 1; i <= n; i++){
                for(auto p: e[i]){
                        int j = p.fi;
                        long long w = p.se;
                        if(d[i] + w == d[j]){
                                v[i].push_back(j);
                                g[j].push_back(i);
                        }
                }
        }
        dfs(s, s);
        for(int i = 0; i < 19; i++){
                f[s][i] = s;
        }
        for(int i = ord.size() - 2; i >= 0; i--){
                int x = ord[i];
                int p = g[x][0];
                for(int j = 1; j < g[x].size(); j++){
                        int y = g[x][j];
                        p = lca(p, y);
                }
                add(x, p);
                ans[x] = 1;
        }
        int best = 0;
        for(int i = 0; i + 1 < ord.size(); i++){
                int x = ord[i];
                ans[f[x][0]] += ans[x];
                best = max(best, ans[x]);
        }
        cout << best << "\n";
}