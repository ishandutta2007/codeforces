#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int pw(int x, int n)
{
        if(n == 0){
                return 1;
        }
        if(n % 2){
                return 1ll * x * pw(x, n - 1) % mod;
        }
        return pw(1ll * x * x % mod, n / 2);
}

int n;
int a[N];
int l[N];
int f[N];
int fac[N];
bool used[N];

void upd(int x, int g)
{
        while(x <= n){
                f[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += f[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        fac[0] = 1;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                l[i] = l[i - 1] + (a[i] == -1);
                fac[i] = 1ll * fac[i - 1] * i % mod;
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                if(a[i] == -1){
                        continue;
                }
                res += get(n) - get(a[i]);
                if(res >= mod){
                        res -= mod;
                }
                used[a[i]] = true;
                upd(a[i], 1);
        }
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        upd(i, -1);
                }
                else{
                        upd(i, 1);
                }
        }
        res = 1ll * res * fac[l[n]] % mod;
        for(int i = 1; i <= n; i++){
                if(a[i] == -1){
                        continue;
                }
                if(l[n] == 0){
                        break;
                }
                int tl = get(a[i]), tr = l[n] - tl;
                int cr = l[i], cl = l[n] - cr;
                res += (1ll * cl * tl % mod) * fac[l[n] - 1] % mod;
                if(res >= mod){
                        res -= mod;
                }
                res += (1ll * cr * tr % mod) * fac[l[n] - 1] % mod;
                if(res >= mod){
                        res -= mod;
                }
        }
        int i = 1ll * l[n] * (l[n] - 1) / 2 % mod;
        i = 1ll * i * i % mod;
        if(l[n] > 2){
                i = 1ll * i * fac[l[n] - 2] % mod;
        }
        res += i;
        if(res >= mod){
                res -= mod;
        }
        res = 1ll * res * pw(fac[l[n]], mod - 2) % mod;
        cout << res << "\n";
}