#include <bits/stdc++.h>

#define MN 200100

using namespace std;
typedef long long ll;

ll a[MN],b[MN],c[MN],d[MN];

int main() {
    ll n, m, k, x, s, ans;

    cin >> n >> m >> k >> x >> s;

    ans = n * x;

    for(int i=0;i<m;i++)
        scanf("%lld", &a[i]);
    for(int i=0;i<m;i++)
        scanf("%lld", &b[i]);
    for(int i=0;i<k;i++)
        scanf("%lld", &c[i]);
    for(int i=0;i<k;i++)
        scanf("%lld", &d[i]);

    int id = upper_bound(d, d + k, s) - d - 1;
        if(id >= 0 && id < k)
            ans = min(ans, x * (n - c[id]));

    for(int i=0;i<m;i++) {
        if(b[i] <= s) {
            id = upper_bound(d, d + k, s - b[i]) - d - 1;
            if(id >= 0 && id < k)
                ans = min(ans, a[i] * (n - c[id]));
            else ans = min(ans, a[i] * n);
        }
    }

    printf("%lld\n",ans);

    return 0;
}