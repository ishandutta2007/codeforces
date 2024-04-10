#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int n;
int m;
int k;
int id[N];
int lev[N][51];
int d[N][51];
int res[N][51];
bool a[N][51];
vector < int > ch[N];
vector < int > v[N], g[N];
vector < int > ord, comp;
bool used[N];

void dfs1(int x)
{
        used[x] = true;
        for(int y: v[x]){
                if(!used[y]){
                        dfs1(y);
                }
        }
        ord.push_back(x);
}

void dfs2(int x)
{
        used[x] = 1;
        comp.push_back(x);
        for(int y: g[x]){
                if(!used[y]){
                        dfs2(y);
                }
        }
}

vector < pair < int, int > > state;
bool us[N][51];
vector < int > ins[N];
bool ggg[N];

void make(int luw)
{
        int st = ch[luw][0];
        int gg = 0;
        for(int it = 0; it < k; it++){
                if(us[st][it]){
                        continue;
                }
                gg++;
                state.clear();
                us[st][it] = 1;
                state.push_back({st, it});
                for(int i = 0; i < (int)state.size(); i++){
                        int x = state[i].fi, g = state[i].se;
                        lev[x][g] = gg;
                        for(int y: ins[x]){
                                int ng = g + 1;
                                if(ng == k){
                                        ng = 0;
                                }
                                if(!us[y][ng]){
                                        us[y][ng] = 1;
                                        state.push_back({y, ng});
                                }
                        }
                        ggg[x] = 0;
                }
                for(int i = 0; i < (int)state.size(); i++){
                        int x = state[i].fi, g = state[i].se;
                        if(ggg[x]){
                                continue;
                        }
                        if(a[x][g]){
                                d[luw][gg]++;
                                ggg[x] = 1;
                        }
                }
        }
}

vector < pair < int, int > > nv[N];

void solve(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        for(auto p: nv[x]){
                int l = p.fi, r = p.se, l1, r1, ni;
                solve(id[r]);
                for(int i = 0; i < k; i++){
                        ni = i + 1;
                        if(ni == k){
                                ni = 0;
                        }
                        l1 = lev[l][i];
                        r1 = lev[r][ni];
                        res[x][l1] = max(res[x][l1], res[id[r]][r1]);
                }
        }
        for(int i = 1; i <= k; i++){
                res[x][i] += d[x][i];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                g[y].push_back(x);
        }
        char c;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < k; j++){
                        cin >> c;
                        a[i][j] = c - '0';
                }
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs1(i);
                }
        }
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        int G = 0;
        for(int i = n - 1; i >= 0; i--){
                int x = ord[i];
                if(used[x]){
                        continue;
                }
                comp.clear();
                dfs2(x);
                G++;
                for(int y: comp){
                        id[y] = G;
                }
                ch[G] = comp;
        }
        for(int i = 1; i <= n; i++){
                for(int j: v[i]){
                        if(id[i] == id[j]){
                                ins[i].push_back(j);
                                continue;
                        }
                        nv[id[i]].push_back({i, j});
                }
                used[i] = 0;
        }
        for(int i = 1; i <= G; i++){
                make(i);
        }
        solve(id[1]);
        cout << res[id[1]][lev[1][0]] << "\n";
}