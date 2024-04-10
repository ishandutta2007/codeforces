#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

using namespace std;

const int N = 606;

long long inf = 1e18;

int n;
long long c[N][N];
long long d[N];
long long f[N];
bool used[N];

void solve(int x)
{
        for(int i = 0; i < n; i++){
                d[i] = inf;
                used[i] = 0;
        }
        d[x] = 0;
        for(int it = 0; it < n - 1; it++){
                x = -1;
                for(int i = 0; i < n; i++){
                        f[i] = inf;

                        if(used[i]){
                                continue;
                        } else if(x == -1 || d[i] < d[x]){
                                x = i;
                        }
                }
                used[x] = true;
                for(int i = 0, j = d[x] % n; i < n; i++){
                        f[j] = c[x][i];
                        j += 1;
                        if(j == n){
                                j = 0;
                        }
                }
                for(int it2 = 0; it2 < 3; it2++){
                        for(int i = 0; i < n; i++){
                                if(i + 1 == n){
                                        f[0] = min(f[0], f[i] + 1);
                                } else{
                                        f[i + 1] = min(f[i + 1], f[i] + 1);
                                }
                        }
                }
                for(int i = 0; i < n; i++){
                        d[i] = min(d[i], d[x] + f[i]);
                }
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        c[i][j] = inf;
                }
        }
        for(int i = 0; i < m; i++){
                int x, y, z;
                cin >> x >> y >> z;
                c[x][y] = z;
        }

        for(int i = 0; i < n; i++){
                solve(i);
                for(int j = 0; j < n; j++){
                        cout << d[j] << " ";
                }
                cout << "\n";
        }
}