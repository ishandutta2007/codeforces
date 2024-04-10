#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n, m;
long long a[N];
pair < long long, long long > b[N];
pair < long long, long long > A[N];
map < pair < long long, long long >, long long > d;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
                scanf("%lld", a + i);
                b[i].fi = (long long)rng();
                b[i].se = (long long)rng();
                A[i] = {0, 0};
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                A[y].fi ^= b[x].fi;
                A[y].se ^= b[x].se;
        }

        d.clear();
        for(int i = 1; i <= n; i++){
                if(A[i].se || A[i].fi){
                        d[A[i]] += a[i];
                }
        }
        long long res = 0;
        for(auto p: d){
                if(!res) res = p.se;
                else res = __gcd(res, p.se);
        }
        printf("%lld\n", res);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        scanf("%d", &t);
        while(t--) solve();
}