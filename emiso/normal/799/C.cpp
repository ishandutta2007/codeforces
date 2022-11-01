#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, c, d, mc[MN], md[MN];
vector<pair<ll, ll>> cf, df;
char z;

int main() {
    scanf("%lld %lld %lld", &n, &c, &d);
    for(int i = 0, x, y; i < n; i++) {
        scanf("%d %d %c", &x, &y, &z);
        if (z == 'C') {
            if (y <= c) cf.push_back({y, x});
        } else if (z == 'D') {
            if (y <= d) df.push_back({y, x});
        } else assert(false);
    }
    ll ans = 0;

    cf.resize(n, {10000000, -10000000});
    df.resize(n, {10000000, -10000000});
    sort(cf.begin(), cf.end());
    sort(df.begin(), df.end());

    mc[0] = cf[0].second;
    md[0] = df[0].second;
    for (int i = 1; i < n; i++) {
        mc[i] = max(mc[i-1], cf[i].second);
        md[i] = max(md[i-1], df[i].second);
    }

    ans = max(ans, mc[n-1] + md[n-1]);

    for (int i = n-1, j = 0; i > 0; i--) {
        while (j + 1 < i && cf[i].first + cf[j+1].first <= c) j++;
        j = min(j, i - 1);
        if (cf[i].first + cf[j].first <= c)
            ans = max(ans, cf[i].second + mc[j]);
    }

    for (int i = n-1, j = 0; i > 0; i--) {
        while (j + 1 < i && df[i].first + df[j+1].first <= d) j++;
        j = min(j, i - 1);
        if (df[i].first + df[j].first <= d)
            ans = max(ans, df[i].second + md[j]);
    }

    printf("%lld\n", ans);
    return 0;
}