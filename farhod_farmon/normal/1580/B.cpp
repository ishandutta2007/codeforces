#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 102;

using namespace std;

int n, m, k, mod;
int d[N][N][N];
int c[N][N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k >> mod;

        m -= 1;
        for(int i = 0; i < N; i++){
                c[i][0] = c[i][i] = 1;
                for(int j = 1; j < i; j++){
                        c[i][j] = c[i - 1][j - 1];
                        add(c[i][j], c[i - 1][j]);
                }
        }
        for(int i = 0; i <= n; i++){
                d[0][i][0] = 1;
        }
        vector<int> A, B;
        for(int x = 1; x <= n; x++){
                for(int i = 0; i < n; i++){
                        for(int y = 0; y < x; y++){
                                A.clear();
                                B.clear();
                                for(int j = 0; j <= k; j++){
                                        if(d[y][i + 1][j]) A.push_back(j);
                                        if(d[x - y - 1][i + 1][j]) B.push_back(j);
                                }
                                for(int &j1: A){
                                        for(int &j2: B){
                                                if(j1 + j2 > k){
                                                        break;
                                                }
                                                add(d[x][i][j1 + j2 + (i == m)], 1ll * d[y][i + 1][j1] * d[x - y - 1][i + 1][j2] % mod * c[x - 1][y] % mod);
                                        }
                                }
                        }
                }
        }
        cout << d[n][0][k] << "\n";
}