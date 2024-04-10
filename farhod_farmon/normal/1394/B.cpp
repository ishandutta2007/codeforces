#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n, m, k;
int ban[10][10][10], slf[10][10];
int used[10], cnt[10][10];
int res, all;
vector < pair < int, int > > v[N], g[N];
int sv[10][10];


void rec(int i)
{
        if(i == k + 1){
                res += (all == n);
                return;
        }
        for(int j = 0; j < i; j++){
                if(used[i] & (1 << j) || slf[i][j]) continue;
                for(int h = i + 1; h <= k; h++){
                        sv[i][h] = used[h];
                        used[h] |= ban[i][j][h];
                }
                all += cnt[i][j];
                rec(i + 1);
                all -= cnt[i][j];
                for(int h = i + 1; h <= k; h++){
                        used[h] = sv[i][h];
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                int x, y, z;
                cin >> x >> y >> z;
                v[x].push_back({z, y});
        }
        for(int i = 1; i <= n; i++){
                sort(v[i].begin(), v[i].end());
                for(int j = 0; j < v[i].size(); j++){
                        g[v[i][j].se].push_back({v[i].size(), j});
                }
        }
        vector < pair < int, int > > ng;
        for(int i = 1; i <= n; i++){
                if(g[i].empty()){
                        cout << 0 << "\n";
                        return 0;
                }
                sort(g[i].begin(), g[i].end());
                ng.clear();
                ng.push_back(g[i][0]);
                for(int j = 1; j < g[i].size(); j++){
                        if(g[i][j] == g[i][j - 1]){
                                slf[g[i][j].fi][g[i][j].se] = true;
                        } else{
                                ng.push_back(g[i][j]);
                        }
                }
                g[i] = ng;
                for(int j = 0; j < g[i].size(); j++){
                        cnt[g[i][j].fi][g[i][j].se] += 1;
                        for(int h = 0; h < g[i].size(); h++) if (h != j){
                                ban[g[i][j].fi][g[i][j].se][g[i][h].fi] |= (1 << g[i][h].se);
                        }
                }
        }
        rec(1);

        cout << res << "\n";
}