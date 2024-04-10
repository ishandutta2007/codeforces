#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
int n, k, c, d, x[20], pos[10];
ll P[10], f[2000010], g[2000010], cur[10];
vector<int> a, b;

int solve(vector<int> p, ll *f) {
    int n = p.size();
    for (int i = 0; i < n; i++) {
        P[i] = cur[i] = p[i], pos[i] = 1;
    }
    int cnt = f[1] = 1;
    for (int i = cnt = 2; ; i++, cnt++) {
        f[i] = LLONG_MAX;
        for (int j = 0; j < n; j++) {
            if (f[i - 1] >= cur[j]) cur[j] = P[j] * f[++pos[j]];
            if (cur[j] < 0 || cur[j] > 1e18) break;
            if (cur[j] < f[i]) f[i] = cur[j];
        }
        if (f[i] > 1e18) break;
    }
    return cnt - 1;
}

int chk(ll x) {
    int ans = 0;
    for (int i = 1, j = d; i <= c; i++) {
        while (j && x / f[i] < g[j]) j--;
        ans += j; if (!j) break;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        if (i & 1) a.push_back(x[i]);
        else b.push_back(x[i]);
    }
    scanf("%d", &k);
    c = solve(a, f), d = solve(b, g);
    ll l = 1, r = 1e18, ans;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) < k ? l = mid + 1 : r = (ans = mid) - 1;
    }
    printf("%lld\n", ans);
    return 0;
}