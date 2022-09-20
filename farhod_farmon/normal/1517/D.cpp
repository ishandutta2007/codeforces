#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 555;
const int mod = 1e9 + 7;

int n, m;
int k;
int A[N][N];
int B[N][N];
int d[N][N], f[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j < m; j++){
                        cin >> A[i][j];
                }
        }
        for(int i = 1; i < n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> B[i][j];
                }
        }
        int inf = 2e9;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        f[i][j] = inf;
                }
        }
        if(k % 2){
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                cout << -1 << " ";
                        }
                        cout << "\n";
                }
                return 0;
        }
        k /= 2;
        for(int it = 0; it < k; it++){
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j < m; j++){
                                f[i][j + 1] = min(f[i][j + 1], d[i][j] + A[i][j]);
                                f[i][j] = min(f[i][j], d[i][j + 1] + A[i][j]);
                        }
                }

                for(int i = 1; i < n; i++){
                        for(int j = 1; j <= m; j++){
                                f[i + 1][j] = min(f[i + 1][j], d[i][j] + B[i][j]);
                                f[i][j] = min(f[i][j], d[i + 1][j] + B[i][j]);
                        }
                }

                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= m; j++){
                                d[i][j] = f[i][j];
                                f[i][j] = inf;
                        }
                }
        }

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cout << d[i][j] * 2 << " ";
                }
                cout << "\n";
        }
}