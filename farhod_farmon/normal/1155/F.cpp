#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 15;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int c[N][N];
int f[1 << N];
int d[1 << N][N];

int ans[N][N];
pair < int, int > g[1 << N];
pair < int, int > p[1 << N];

void make(int x)
{
        for(int i = 0; i < (1 << n); i++){
                for(int j = 0; j < n; j++){
                        d[i][j] = -1;
                }
        }
        d[1 << x][x] = x;

        for(int i = 0; i < (1 << n); i++){
                for(int j = 0; j < n; j++){
                        if(d[i][j] == -1){
                                continue;
                        }
                        for(int h = 0; h < n; h++){
                                if(!c[j][h]){
                                        continue;
                                }
                                if(i & (1 << h)){
                                        if(h == x && __builtin_popcount(i) > 2 && p[i].fi == -1){
                                                p[i] = {x, j};
                                        }
                                        continue;
                                }
                                int ni = i | (1 << h);
                                if(d[ni][h] == -1){
                                        d[ni][h] = j;
                                }
                        }
                }
        }
}

bool used[N];

void dfs(int x)
{
        if(used[x]) return;
        used[x] = 1;
        for(int y = 0; y < n; y++){
                if(ans[x][y] || ans[y][x]){
                        dfs(y);
                }
        }
}

bool con()
{
        for(int i = 0; i < n; i++){
                used[i] = 0;
        }
        dfs(0);
        for(int i = 0; i < n; i++){
                if(!used[i]){
                        return false;
                }
        }
        return true;
}

bool good()
{
        for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        if(ans[i][j] || ans[j][i]){
                                ans[i][j] = ans[j][i] = 0;
                                if(!con()){
                                        ans[i][j] = ans[j][i] = 1;
                                        return false;
                                } else{
                                        ans[i][j] = ans[j][i] = 1;
                                }
                        }
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;

                c[x - 1][y - 1] = 1;
                c[y - 1][x - 1] = 1;
        }

        for(int i = 0; i < (1 << n); i++){
                p[i] = {-1, -1};
                g[i] = {-1, -1};
        }
        for(int i = 0; i < n; i++){
                make(i);
        }

        vector < int > v;
        for(int i = 1; i < (1 << n); i++){
                f[i] = 1e9;
                if(p[i].fi != -1){
                        g[i] = {0, i};
                        f[i] = 1;
                        continue;
                }

                v.clear();
                for(int j = (i - 1) & i; j > 0; j = (j - 1) & i){
                        if(__builtin_popcount(j) > 2){
                                v.push_back(j);
                        }
                }

                for(int s: v){
                        if(g[s].fi == -1){
                                continue;
                        }
                        for(int t: v){
                                if((s | t) != i || (s & t) == 0 || p[t].fi == -1){
                                        continue;
                                }
                                int cost = __builtin_popcount(s & t);
                                if(f[s] + 1 < f[i]){
                                        f[i] = f[s] + 1;
                                        g[i] = {s, t};
                                }
                        }
                }
        }

        int mask = (1 << n) - 1;

        while(mask > 0){
                int ns = g[mask].se;
                auto gg = p[ns];
                mask = g[mask].fi;

                make(gg.fi);

                ans[gg.fi][gg.se] = 1;
                while(gg.se != gg.fi){
                        int y = d[ns][gg.se];
                        ans[gg.se][y] = 1;
                        ns ^= (1 << gg.se);
                        gg.se = y;
                }

        }

        for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        if(ans[i][j] || ans[j][i]){
                                ans[i][j] = ans[j][i] = 0;
                                if(!good()){
                                        ans[i][j] = ans[j][i] = 1;
                                }
                        }
                }
        }

        vector < pair < int, int > > res;
        for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        if(ans[i][j] || ans[j][i]){
                                res.push_back({i, j});
                        }
                }
        }
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi + 1 << " " << p.se + 1 << "\n";
        }
}