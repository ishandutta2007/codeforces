#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int mod = 1e9 + 7;

using namespace std;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

int n;
int m;
int d[11][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                d[1][i] = 1;
        }
        for(int i = 2; i <= m; i++){
                for(int j = 1; j <= n; j++){
                        for(int h = j; h <= n; h++){
                                add(d[i][h], d[i - 1][j]);
                        }
                }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        add(res, 1ll * d[m][i] * d[m][n - j + 1] % mod);
                }
        }
        cout << res << "\n";
}