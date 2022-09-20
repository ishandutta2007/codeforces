#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 998244353;

using namespace std;

int n, m, k;
int L[N], R[N];
int l[N], r[N], d[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                int L, R;
                cin >> L >> R;
                for(int j = 1, cur; j <= n; j++){
                        cur = min(R, j + k - 1) - max(L, j) + 1;
                        if(cur > d[i]){
                                d[i] = cur;
                                l[i] = r[i] = j;
                        } else if(cur == d[i]){
                                r[i] = j;
                        }
                }
                ::L[i] = L;
                ::R[i] = R;
        }

        int res = 0;
        vector < int > cur(m + 1);
        vector < int > tp(m + 1);
        for(int i = 1; i <= n; i++){
                int cnt = 0, df = 0;
                for(int j = 1; j <= n; j++){
                        v[j].clear();
                }
                for(int j = 1, x; j <= m; j++){
                        cur[j] = min(R[j], i + k - 1) - max(L[j], i) + 1;
                        cur[j] = max(cur[j], 0);
                        cnt += cur[j];
                        tp[j] = 0;

                        x = max(1, cur[j] - d[j] + l[j]);
                        v[x].push_back(j);
                        v[l[j]].push_back(j);
                        v[r[j] + 1].push_back(j);
                        //cout << cur[j] << " " << x << " ";

                        x = min(n, d[j] + r[j] - cur[j]);
                        //cout << x << "\n";
                        v[x].push_back(j);
                }
                for(int j = 1; j <= n; j++){
                        for(int h: v[j]){
                                if(tp[h] == 0){
                                        cnt -= cur[h];
                                        cnt += d[h] - l[h];
                                        df += 1;
                                } else if(tp[h] == 1){
                                        df -= 1;
                                        cnt -= d[h] - l[h];
                                        cnt += d[h];
                                } else if(tp[h] == 2){
                                        df -= 1;
                                        cnt -= d[h];
                                        cnt += d[h] + r[h];
                                } else{
                                        cnt -= d[h] + r[h];
                                        cnt += cur[h];
                                        df += 1;
                                }
                                tp[h] += 1;
                        }
                        //cout << i << " " << j << ' ' << cnt + j * df << " " << df << "\n";
                        res = max(res, cnt + j * df);
                }
        }

        cout << res << "\n";
}