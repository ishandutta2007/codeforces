#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;
const int Q = 10000011;
const long long mod = 998244353;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n){
                if(n & 1){
                        res = res * x % mod;
                }
                n /= 2;
                x = x * x % mod;
        }
        return res;
}

int n;
int m;
long long S;
long long a[N];
long long w[N];
long long d[N][N][N];
long long f[N][N][N];

void add(long long &x, long long y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

long long solve(int x)
{
        long long res = 0;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        for(int h = 0; h < N; h++){
                                d[i][j][h] = f[i][j][h] = 0;
                        }
                }
        }
        d[0][0][0] = 1;
        long long A = 0, B = 0;
        long long ns, nw, na, nb, inv;
        for(int i = 1; i <= n; i++){
                if(i == x){
                        continue;
                }
                if(a[i]){
                        A += w[i];
                } else{
                        B += w[i];
                }
        }
        for(int it = 1; it <= m; it++){
                for(int i = 0; i <= m; i++){
                        for(int j = 0; j <= m; j++){
                                for(int h = 0; h <= m; h++){
                                        if(!d[i][j][h]){
                                                continue;
                                        }
                                        ns = S + i - j, nw = w[x] + h * (a[x] ? 1 : -1);
                                        inv = pw(ns, mod - 2);
                                        add(f[i + a[x]][j + !a[x]][h + 1], d[i][j][h] * (nw * inv % mod) % mod);
                                        na = A + i;
                                        nb = B - j;
                                        if(a[x]){
                                                na -= h;
                                        } else{
                                                nb += h;
                                        }
                                        add(f[i + 1][j][h], d[i][j][h] * (na * inv % mod) % mod);
                                        add(f[i][j + 1][h], d[i][j][h] * (nb * inv % mod) % mod);
                                }
                        }
                }
                for(int i = 0; i <= m; i++){
                        for(int j = 0; j <= m; j++){
                                for(int h = 0; h <= m; h++){
                                        d[i][j][h] = f[i][j][h];
                                        f[i][j][h] = 0;
                                }
                        }
                }
        }
        for(int i = 0; i <= m; i++){
                for(int j = 0; j <= m; j++){
                        for(int h = 0; h <= m; h++){
                                nw = w[x] + h * (a[x] ? 1 : -1);
                                add(res, nw * d[i][j][h] % mod);
                        }
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> w[i];
                S += w[i];
        }
        for(int i = 1; i <= n; i++){
                cout << solve(i) << "\n";
        }
}