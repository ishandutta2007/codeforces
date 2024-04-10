#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];
long long d[N + N];
long long f[N + N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        a[n + 1] = a[1];
        d[n] = 1;
        for(int i = 1; i <= n; i++){
                int c0 = max(0, k - 2), c1 = 0, c2 = 0;
                if(a[i] == a[i + 1]){
                        c0 = k;
                } else{
                        c1 = c2 = 1;
                }
                for(int j = 0; j <= n + n; j++){
                        f[j] += d[j] * c0 % mod;
                        if(j - 1 >= 0){
                                f[j - 1] += d[j] * c2 % mod;
                        }
                        f[j + 1] += d[j] * c1 % mod;
                }
                for(int j = 0; j <= n + n; j++){
                        d[j] = f[j] % mod;
                        f[j] = 0;
                }
        }
        long long res = 0;
        for(int i = n + 1; i <= n + n; i++){
                res += d[i];
        }
        res %= mod;
        cout << res << "\n";
}