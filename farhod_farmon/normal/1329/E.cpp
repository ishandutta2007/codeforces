#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;

using namespace std;

int m;
long long a[N];
long long n, k;
vector < pair < long long, long long > > v;
vector < pair < long long, long long > > mn;
vector < pair < long long, long long > > mx;
multiset < long long > S;

void solve()
{
        scanf("%lld%d%lld", &n, &m, &k);
        for(int i = 1; i <= m; i++){
                scanf("%lld", a + i);
        }
        a[++m] = n;
        for(int i = m; i >= 1; i--){
                a[i] -= a[i - 1];
        }
        k += m;

        long long l = 1, r = n;
        while(l < r){
                long long R = (l + r) / 2;
                long long cnt = 0;
                for(int i = 1; i <= m; i++){
                        cnt += (a[i] - 1) / R + 1;
                }
                if(cnt <= k){
                        r = R;
                } else{
                        l = R + 1;
                }
        }
        long long R = l;
        l = 1, r = n;
        for(int i = 1; i <= m; i++) r = min(r, a[i]);
        while(l < r){
                long long L = (l + r) / 2 + 1;
                long long cnt = 0;
                for(int i = 1; i <= m; i++){
                        cnt += a[i] / L;
                }
                if(cnt >= k){
                        l = L;
                } else{
                        r = L - 1;
                }
        }
        long long L = l;

        v.clear();

        for(int i = 1; i <= m; i++){
                long long x = a[i] / L;
		long long y = (a[i] - 1) / R + 1;
		if (x >= y) continue;
                v.push_back({a[i] / y, (a[i] - 1) / x + 1});
        }
        sort(v.begin(), v.end());
        l = L, r = R;
        long long res = n;
        if(v.empty()){
                res = R - L;
        } else{
                res = max(v.back().fi, R) - min(v[0].fi, L);
        }
        for(int i = 0; i < v.size(); i++){
                l = min(l, v[i].se);
                r = max(r, v[i].se);

                long long tl = l, tr = r;
                if(i + 1 < v.size()){
                        tl = min(tl, v[i + 1].fi);
                        tr = max(tr, v.back().fi);
                }

                res = min(res, max(tr, R) - min(tl, L));
        }

        printf("%lld\n", res);
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        scanf("%d", &T);
        while(T--){
                solve();
        }
}