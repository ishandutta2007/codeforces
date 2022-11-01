#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    map<int, int> f;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    int most = f[a[0]];
    for (auto tt : f) {
        if (tt.second > most)
            most = tt.second;
    }

    ll tmp = most;
    while (tmp < n) {
        ans++;
        ans += min(tmp, n - tmp);
        tmp *= 2;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}