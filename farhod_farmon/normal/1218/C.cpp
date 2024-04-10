#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 550;

using namespace std;

int n;
int m;
int k;
long long d[N][N][2];
long long cost[N][N];
vector < pair < int, long long > > R[N][N];
vector < pair < int, long long > > D[N][N];
vector < pair < int, long long > > nv;

void normal(vector < pair < int, long long > > &v)
{
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
                v[i].se += v[i - 1].se;
        }
}

void upd(long long &x, long long y)
{
        x = min(x, y);
}

bool good(vector < pair < int, int > > &g, int i, int t)
{
        int cur = g[i].fi + g[i].se;
        if(cur >= t && (cur - t) % 4 == i){
                return true;
        }
        return false;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d%d%d", &n, &m, &k);
        vector < pair < int, int > > g;
        for(int i = 1, x, y, d, t, e; i <= k; i++){
                scanf("%d%d%d%d%d", &x, &y, &d, &t, &e);

                g.clear();
                g.push_back({x, y});
                g.push_back({x + d, y - d});
                g.push_back({x + d, y});
                g.push_back({x, y + d});

                for(int i = 0; i < 4; i++){
                        if(good(g, i, t)){
                                cost[g[i].fi][g[i].se] += e;
                        }
                }
                if(good(g, 0, t) && good(g, 3, t)){
                        R[g[3].fi][g[3].se].push_back({g[0].se, e});
                }
                if(good(g, 0, t) && good(g, 2, t)){
                        D[g[2].fi][g[2].se].push_back({g[0].fi, e});
                }
                if(good(g, 1, t) && good(g, 2, t)){
                        R[g[2].fi][g[2].se].push_back({g[1].se, e});
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        normal(R[i][j]);
                        normal(D[i][j]);
                }
        }

        for(int i = 0; i <= n; i++){
                for(int j = 0; j <= m; j++){
                        d[i][j][0] = 1e18;
                        d[i][j][1] = 1e18;
                }
        }

        d[0][0][0] = 0;
        d[0][0][1] = 0;

        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        long long cnt = d[i][j][1];
                        for(int h = j + 1; h < m; h++){
                                while(!R[i][h].empty() && R[i][h].back().fi < j){
                                        R[i][h].pop_back();
                                }
                                if(!R[i][h].empty()){
                                        cnt -= R[i][h].back().se;
                                }
                                cnt += cost[i][h];
                                upd(d[i][h][0], cnt);
                        }
                        cnt = d[i][j][0];
                        for(int h = i + 1; h < n; h++){
                                while(!D[h][j].empty() && D[h][j].back().fi < i){
                                        D[h][j].pop_back();
                                }
                                if(!D[h][j].empty()){
                                        cnt -= D[h][j].back().se;
                                }
                                cnt += cost[h][j];
                                upd(d[h][j][1], cnt);
                        }
                }
        }

        printf("%lld\n", min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]) + cost[0][0]);
}