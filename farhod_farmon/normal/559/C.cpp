#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int d[N];
int fac[N];

long long pw(long long x, long long n)
{
        if(n == 0){
                return 1;
        }
        if(n % 2){
                return x * pw(x, n - 1) % mod;
        }
        else{
                return pw(x * x % mod, n / 2);
        }
}

int C(int n, int k)
{
        if(n < k){
                return 0;
        }
        return 1ll * fac[n] * pw(1ll * fac[k] * fac[n - k] % mod, mod - 2) % mod;
}

int ways(int x1, int y1, int x2, int y2)
{
        if(x1 > x2 || y1 > y2){
                return 0;
        }
        x2 -= x1 - 1;
        y2 -= y1 - 1;
        return C(x2 + y2 - 2, x2 - 1);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        vector < pair < int, int > > v;
        for(int i = 1; i <= k; i++){
                int x, y;
                cin >> x >> y;
                v.push_back({x, y});
        }
        v.push_back({n, m});
        sort(v.begin(), v.end());
        fac[0] = 1;
        for(int i = 1; i < N; i++){
                fac[i] = 1ll * fac[i - 1] * i % mod;
        }
        for(int i = 0; i <= k; i++){
                d[i] = ways(1, 1, v[i].fi, v[i].se);
                for(int j = 0; j < i; j++){
                        d[i] -= 1ll * d[j] * ways(v[j].fi, v[j].se, v[i].fi, v[i].se) % mod;
                        if(d[i] < 0){
                                d[i] += mod;
                        }
                }
        }
        cout << d[k] << "\n";
}