#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int mod = 1e9 + 7;

using namespace std;

int n, m, k;
int a[N];
int b[N];
int c[N];
int r[N];
vector < int > v[N];
int d[N];
int f[N];


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i] >> c[i];

                r[i] = i;
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                r[y] = max(r[y], x);
        }
        for(int i = 1; i <= n; i++){
                v[r[i]].push_back(c[i]);
        }

        int s = 0;
        for(int i = 1; i <= n; i++){
                if(k < a[i]){
                        cout << -1 << "\n";
                        return 0;
                }
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
                for(int j = 1; j < v[i].size(); j++){
                        v[i][j] += v[i][j - 1];
                }
                for(int j = 0; j <= s; j++){
                        if(k - j < a[i]){
                                break;
                        }
                        f[j] = max(f[j], d[j]);
                        for(int h = 0; h < v[i].size(); h++){
                                f[j + h + 1] = max(f[j + h + 1], d[j] + v[i][h]);
                        }
                }
                k += b[i];
                s += v[i].size();
                for(int j = 0; j <= s; j++){
                        d[j] = f[j];
                        f[j] = 0;
                }
        }

        int res = 0;
        for(int i = 0; i < N; i++){
                res = max(res, d[i]);
        }

        cout << res << "\n";
}