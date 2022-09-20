#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 404;

using namespace std;

int n;
int m;
int b[N];
int c[N];
int f[N];
int s[N][N];
char a[N][N];

int get(int x1, int y1, int x2, int y2)
{
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

void solve()
{
        cin >> n >> m;

        for(int i = 0; i <= n + 1; i++){
                for(int j = 0; j <= m + 1; j++){
                        s[i][j] = 0;
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        a[i][j] -= '0';
                        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
                }
        }

        int res = n * m;
        for(int i = 1; i + 4 <= n; i++){
                for(int j = 1; j <= m; j++){
                        b[j] = c[j] = 0;
                        c[j] += !a[i][j];
                        c[j] += !a[i + 1][j];
                }
                for(int j = i + 2; j <= n; j++){
                        for(int h = 1; h <= m; h++){
                                b[h] += !a[j - 1][h];
                                c[h] -= !a[j - 1][h];
                                c[h] += a[j - 1][h];
                        }
                        for(int h = 1; h <= m; h++){
                                c[h] += !a[j][h];
                        }
                        if(j - i >= 4){
                                for(int h = 1; h <= m; h++){
                                        f[h] = f[h - 1] + c[h];
                                }
                                int mx = 1e9;
                                for(int h = 1; h <= m; h++){
                                        if(h - 3 > 0){
                                                mx = min(mx, b[h - 3] - f[h - 3]);
                                        }
                                        res = min(res, mx + b[h] + f[h - 1]);
                                }
                        }
                }
        }

        cout << res << "\n";
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