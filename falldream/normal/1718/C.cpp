#include<bits/stdc++.h>
#define MN 200000
#define MM 450
#define N 1048576
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, m, q, a[MN + 5], lt[MM + 5], rt[MM + 5];
vector<int> fac;
vector<ll> sum[MM * 2 + 5];
ll T[N * 2 + 5];

// ll query(int l, int r)
// {
//     ll mx=0;
//     for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
//     {
//         if(~l&1) mx = max(mx, T[l+1]);
//         if( r&1) mx = max(mx, T[r-1]);    
//     }
//     return mx;
// }

void renew(int x, ll v)
{
    T[x += N] = v;
    for(x >>= 1;x;x >>= 1)
       T[x] = max(T[x << 1], T[(x << 1) | 1]);
}

int main() {
    for (int qq=read();qq--;) {
        n = read(); q = read();
        fac.clear(); int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        for (int i = 2, nn = n; nn > 1; ++i) {
            if (n % i == 0) {
                fac.push_back(n / i);
                lt[fac.size() - 1] = cnt + 1;
                rt[fac.size() - 1] = cnt + (n / i);
                cnt += n / i;
                while (nn % i == 0) {
                    nn /= i;
                }
            }
        }
        m = fac.size();
        ll ans = 0;
        for (int j = 0; j < m; ++j) {
            int t = fac[j];
            sum[j].resize(t, 0);
            for (int i = 0; i < t; ++i) sum[j][i] = 0;
            for (int i = 1; i <= n; ++i) {
                sum[j][i % t] += a[i];
            }
            for (int i = 0; i < t; ++i) {
                renew(lt[j] + i, sum[j][i] * t);
            }
        }
        printf("%lld\n", T[1]);
        for (int i = 1; i <= q; ++i) {
            int x = read(), v = read();
            for (int j = 0; j < m; ++j) {
                int t = fac[j];
                sum[j][x % t] += v - a[x];
                renew(lt[j] + (x % t), sum[j][x % t] * t);
            }
            a[x] = v;
            printf("%lld\n", T[1]);
        }
        for (int i = 1; i <= cnt; ++i) {
            renew(i, 0);
        }
    }
    return 0;
}