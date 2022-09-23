#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;
const long long mod = 998244353;

using namespace std;

int n;
int c;
int a[N];
int p[N];
int res[N];
int d[N][N];
int g[N][N];
int f1[N][1 << 12];

void upd(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

void solve1()
{
        int nj, nk, last = (1 << c) - 1;
        for(int i = 1; i <= n; i++){
                for(int j = (i - 1) / c; j >= 0; j--){
                        for(int k = last - 1; k >= 0; k--){
                                nj = j;
                                nk = k | (1 << a[i]);
                                if(nk == last){
                                        nj += 1;
                                        nk = 0;
                                        upd(d[i][nj], f1[j][k]);
                                }
                                upd(f1[nj][nk], f1[j][k]);
                        }
                }
                if(c == 1){
                        upd(d[i][1], 1);
                        upd(f1[1][0], 1);
                } else{
                        upd(f1[0][1 << a[i]], 1);
                }
        }
}

long long pw(long long x, long long n)
{
        long long res = 1;
        while(n){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

int t[N];
int inv[N];

void solve2()
{
        for(int i = 1; i < n; i++){
                inv[i] = pw(p[i] - 1, mod - 2);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < c; j++){
                        t[j] = 0;
                }
                int j = i - 1;
                int sad = c;
                while(j < n && sad){
                        j += 1;
                        t[a[j]] += 1;
                        sad -= t[a[j]] == 1;
                }
                if(sad){
                        break;
                }
                long long res = 1;
                for(int h = 0; h < c; h++){
                        res = res * (p[t[h]] - 1) % mod;
                }
                sad = 1;
                for(; j <= n; j++){
                        res = res * inv[t[a[j]]] % mod;
                        g[i][j] = res;
                        if(sad){
                                sad = 0;
                        } else{
                                t[a[j]] += 1;
                        }
                        res = res * (p[t[a[j]]] - 1) % mod;
                }
        }
        d[0][0] = 1;
        /*
        for(int i = 1; i <= n; i++){
                for(int j = i / c - 1; j >= 0; j--){
                        for(int h = 0; h < i; h++){
                                if(!g[h + 1][i]){
                                        break;
                                }
                                upd(d[i][j + 1], 1ll * d[h][j] * g[h + 1][i] % mod);
                        }
                }
        }
        */
        int k = n / c;
        d[0][0] = 1;
        long long sum, MOD = mod, MOD2 = mod * mod;
        for (int r = 1; r <= k; r++)
        {
                d[0][r] = 0;
                for (int i = r * c - 1; i < n; i++)
                {
                        sum = 0;
                        for (int j = i; j >= (r - 1) * c; j--)
                        {
                                sum += 1LL * g[j + 1][i + 1] * d[j][r - 1];
                                if (sum >= MOD2) sum -= MOD2;
                        }
                        d[i + 1][r] = (sum % MOD);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> c;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= 1;
        }
        p[0] = 1;
        for(int i = 1; i <= n; i++){
                p[i] = p[i - 1];
                upd(p[i], p[i]);
        }
        if(c <= 10){
                solve1();
        } else{
                solve2();
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        upd(res[j], 1ll * d[i][j] * p[n - i] % mod);
                }
        }
        res[0] = p[n];
        upd(res[0], -1);
        for(int i = 0; i <= n; i++){
                upd(res[i], - res[i + 1]);
                cout << res[i] << " ";
        }
}