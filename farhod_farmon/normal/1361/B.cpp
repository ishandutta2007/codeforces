#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

long long pw(long long x, long long n)
{
        long long res = 1;
        x %= mod;
        while(n > 0){
                if(n & 1){
                        res = res * x % mod;
                }
                n /= 2;
                x = x * x % mod;
        }
        return res;
}

int n;
long long p;
long long a[N];
long long bib = 1e6 + 10;
vector < pair < long long, long long > > v;

long long pw2(long long x, long long n)
{
        long long res = 1;
        while(n > 0){
                if(n & 1){
                        res = 1ll * res * x;
                        res = min(res, bib);
                }
                x = 1ll * x * x;                x = min(x, bib);
                n /= 2;
        }
        return res;
}

void add(long long &x, long long y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

void solve()
{
        scanf("%d%lld", &n, &p);
        for(int i = 0; i < n; i++){
                scanf("%lld", &a[i]);
        }
        sort(a, a + n);
        v.clear();
        for(int i = 0; i < n; i++){
                if(!v.empty() && v.back().fi == a[i]){
                        v.back().se += 1;
                } else{
                        v.push_back({a[i], 1});
                }
        }
        int h = (int)v.size() - 1;
        long long res = 0;
        for(int i = (int)v.size() - 1; i >= 0; i--){
                if(v[i].se % 2 == 0){
                        continue;
                }
                h = min(h, i - 1);
                long long need = pw2(p, v[i].fi - v[h].fi);

                res = pw(p, v[i].fi);
                while(h >= 0 && need > 0){
                        add(res, - 1ll * pw(p, v[h].fi) * v[h].se % mod);
                        long long g = min(need, v[h].se);
                        need -= g;
                        v[h].se -= g;
                        if(v[h].se == 0){
                                if(h > 0){
                                        need = min(need * pw2(p, v[h].fi - v[h - 1].fi), bib);
                                }
                                h -= 1;
                        }
                }
                if(need > 0){
                        break;
                }
                res = 0;
        }
        printf("%lld\n", res);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        scanf("%d", &t);
        while(t--){
                solve();
        }
}