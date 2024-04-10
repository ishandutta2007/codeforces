#include <bits/stdc++.h>

#define fi first
#define se second

const int N = (int)sqrt(100000) + 5;
const int mod = (int)1e9 + 7;

using namespace std;

int n;
int m;
int d[N][N][2];
int f[N][N][2];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int x;
        cin >> n >> m >> x;
        if(n > m){
                cout << 0 << "\n";
                return 0;
        }
        f[0][0][0] = 1;
        for(int i = 1; i <= m; i++){
                for(int j = 0; j <= n; j++){
                        for(int h = 0; h <= n; h++){
                                for(int g = 0; g < 2; g++){
                                        if(h > 0){
                                                add(d[j][h - 1][g], f[j][h][g]);
                                                add(d[j + 1][h][g | (i == x)], f[j][h][g]);
                                        }
                                        add(d[j][h][g], f[j][h][g]);
                                        add(d[j + 1][h + 1][g | (i == x)], f[j][h][g]);
                                        if(h == 0){
                                                add(d[j + 1][h][g | (i == x)], f[j][h][g]);
                                        }
                                }
                        }
                }
                for(int j = 0; j <= n; j++){
                        for(int h = 0; h <= n; h++){
                                for(int g = 0; g < 2; g++){
                                        f[j][h][g] = d[j][h][g];
                                        d[j][h][g] = 0;
                                }
                        }
                }
        }
        int res = f[n][0][1];
        for(int i = 1; i <= n; i++){
                res = 1ll * res * i % mod;
        }
        cout << res << "\n";
}