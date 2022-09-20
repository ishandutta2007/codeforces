#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 660;
const int Q = N * N;

int n, m, q;
int a[Q], b[Q], c[Q], res[Q];
int d[N][N];
int shit[N];
int inf = 1e9;
vector < int > qu[N];
int u[Q], v[Q], l[Q];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);


        for(int i = 1; i < N; i++){
                for(int j = 1; j < N; j++){
                        d[i][j] = inf;
                }
                d[i][i] = 0;
        }

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i] >> b[i] >> c[i];

                d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
                d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i]);
        }

        cin >> q;
        for(int i = 1; i <= q; i++){
                cin >> u[i] >> v[i] >> l[i];
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        for(int h = 1; h <= n; h++){
                                d[j][h] = min(d[j][h], d[j][i] + d[i][h]);
                        }
                }
        }

        for(int i = 1; i <= q; i++){
                qu[u[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        shit[j] = - inf;
                        for(int h: qu[i]){
                                shit[j] = max(shit[j], l[h] - d[j][v[h]]);
                        }
                }
                for(int j = 1; j <= m; j++){
                        if(d[i][a[j]] + c[j] <= shit[b[j]] || d[i][b[j]] + c[j] <= shit[a[j]]){
                                res[j] = 1;
                        }
                }
        }

        int cnt = 0;
        for(int i = 1; i <= m; i++){
                cnt += res[i];
        }

        cout << cnt << "\n";
}