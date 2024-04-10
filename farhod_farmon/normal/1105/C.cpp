#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int l;
int r;
int c[3];
int d[N][3];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> l >> r;
        while(l <= r && l % 3){
                c[l % 3] += 1;
                l += 1;
        }
        while(l <= r && r % 3 != 2){
                c[r % 3] += 1;
                r -= 1;
        }
        c[0] += (r - l + 1) / 3;
        c[1] += (r - l + 1) / 3;
        c[2] += (r - l + 1) / 3;
        d[0][0] = 1;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 3; j++){
                        for(int h = 0; h < 3; h++){
                                int nj = (j + h) % 3;
                                d[i][nj] += 1ll * d[i - 1][j] * c[h] % mod;
                                if(d[i][nj] >= mod){
                                        d[i][nj] -= mod;
                                }
                        }
                }
        }
        cout << d[n][0] << "\n";
}