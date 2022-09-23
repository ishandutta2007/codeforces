#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 4040;

using namespace std;

int n, m;
int l[N], s[N];
int cost[N];
int inf = -1e9;
int d[N][N];
int f[N][N];
vector < int > v[N];
vector < int > pos[N];
vector < int > fut[N][14];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> l[i];
        for(int i = 1; i <= n; i++) cin >> s[i];
        reverse(l + 1, l + n + 1);
        reverse(s + 1, s + n + 1);
        for(int i = 1; i <= n + m; i++) cin >> cost[i];
        for(int i = 1; i <= n; i++) v[l[i]].push_back(i);

        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) d[i][j] = inf;

        for(int i = 1; i <= n + m; i++){
                for(int j = 0; j < 13; j++){
                        fut[i][j].resize((1 << 13 - j));
                        while(fut[i][j].size() >= N - 4) fut[i][j].pop_back();
                        for(auto &x: fut[i][j]) x = inf;
                }
        }

        for(int i = 0; i < N; i++){
                for(int j = 1; j <= n + m; j++){
                        f[i][j] = cost[j];
                        for(int h = 0; h < 13; h++){
                                if(i & (1 << h)) f[i][j] += cost[j + h + 1];
                                else break;
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= l[i]; j++){
                        int dif = min(12, l[i] - j);
                        for(int p = 0; p < fut[j][dif].size(); p++){
                                d[p + 1][i] = max(d[p + 1][i], fut[j][dif][p] + f[p][l[i]] - s[i]);
                        }
                }
                d[1][i] = max(d[1][i], cost[l[i]] - s[i]);


                for(int j = 0; j < N; j++){
                        int nj = j, x = l[i];
                        for(int h = 0; h < 13; h++){
                                fut[x][h][nj] = max(fut[x][h][nj], d[j][i]);
                                nj >>= 1;
                        }
                }
        }

        int res = 0;

        for(int i = 0; i < N; i++){
                for(int j = 1; j <= n; j++){
                        res = max(res, d[i][j]);
                }
        }

        cout << res << "\n";
}