#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 101;
const int mod = 998244353;

int inf = 1e9;

int n;
int s[N];
vector < vector < vector < int > > > f[N];
vector < vector < vector < int > > > d;
vector < int > v[N], res;

void dfs(int x)
{
        s[x] = 1;
        d[x][1][0] = 0;
        f[x].push_back(d[x]);
        for(int y: v[x]){
                dfs(y);

                for(int i = s[x]; i > 0; i--){
                        for(int j = s[y]; j > 0; j--){
                                for(int h1 = 0; h1 < s[x]; h1++){
                                        for(int h2 = 0; h2 < s[y]; h2++){
                                                d[x][i + j][max(h1, h2 + 1)] = min(
                                                d[x][i + j][max(h1, h2 + 1)],
                                                d[x][i][h1] + d[y][j][h2] + min(h1, h2 + 1) + 1);
                                        }
                                }
                        }
                }

                f[x].push_back(d[x]);
                s[x] += s[y];
        }
}

void trace(int x, int k, int dip, int p = -1, int up = false)
{
        res.push_back(x);

        vector < int > gg;

        for(int h = v[x].size() - 1; h >= 0; h--){
                int y = v[x][h];
                if(f[x][h][k][dip] == f[x][h + 1][k][dip]){
                        s[x] -= s[y];
                        continue;
                }

                int fo = 0;
                for(int i = s[x]; i > 0 && !fo; i--){
                        int j = k - i;
                        if(j < 1 || j > s[y]){
                                continue;
                        }
                        for(int h1 = 0; h1 < s[x] && !fo; h1++){
                                for(int h2 = 0; h2 < s[y] && !fo; h2++){
                                        if(max(h1, h2 + 1) == dip && f[x][h][i][h1] + d[y][j][h2] + min(h1, h2 + 1) + 1 == f[x][h + 1][k][dip]){
                                                if(up || h2 + 1 <= h1 || !gg.empty()){
                                                        trace(y, j, h2, x, 1);
                                                } else{
                                                        gg = {y, j, h2, x, 0};
                                                }

                                                fo = true;
                                                dip = h1;
                                                k = i;
                                        }
                                }
                        }
                }

                s[x] -= s[y];
        }

        if(!gg.empty()){
                trace(gg[0], gg[1], gg[2], gg[3], gg[4]);
        }

        if(up){
                res.push_back(p);
        }
}

void solve()
{
        d.resize(N);
        for(int i = 0; i < N; i++){
                v[i].clear();
                d[i].resize(N);
                f[i].clear();
                for(int j = 0; j < N; j++){
                        d[i][j].resize(N);
                        for(int h = 0; h < N; h++){
                                d[i][j][h] = inf;
                        }
                }
        }
        res.clear();


        int k;
        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x;
                cin >> x;
                v[x - 1].push_back(i);
        }

        dfs(0);

        int best = inf, dip;
        for(int i = 0; i < n; i++){
                if(d[0][k][i] < best){
                        best = d[0][k][i];
                        dip = i;
                }
        }

        trace(0, k, dip);

        cout << res.size() - 1 << "\n";
        for(int x: res){
                cout << x + 1 << " ";
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}