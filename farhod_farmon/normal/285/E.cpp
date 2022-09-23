#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k;
int c[N][N];
int d[N][N][2][2];
int res[N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 0; i <= n; i++){
                c[i][0] = c[i][i] = 1;
                for(int j = 1; j < i; j++){
                        add(c[i][j], c[i - 1][j]);
                        add(c[i][j], c[i - 1][j - 1]);
                }
        }
        d[0][0][0][0] = 1;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j <= i; j++){
                        for(int a = 0; a < 2; a++){
                                for(int b = 0; b < 2; b++){
                                        int prev = d[i - 1][j][a][b];
                                        add(d[i][j][b][0], prev);
                                        if(a == 0 && i > 1){
                                                add(d[i][j + 1][b][0], prev);
                                        }
                                        if(i < n){
                                                add(d[i][j + 1][b][1], prev);
                                        }
                                }
                        }
                }
        }
        for(int i = n; i >= k; i--){
                for(int a = 0; a < 2; a++){
                        for(int b = 0; b < 2; b++){
                                add(res[i], d[n][i][a][b]);
                        }
                }
                for(int j = 1; j <= n - i; j++){
                        res[i] = res[i] * 1ll * j % mod;
                }
                for(int j = i + 1; j <= n; j++){
                        add(res[i], - res[j] * 1ll * c[j][i] % mod);
                }
        }
        cout << res[k] << "\n";
}