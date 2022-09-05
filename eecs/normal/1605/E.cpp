#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, a[maxn], b[maxn];
ll c[maxn], d[maxn], pre1[maxn], pre2[maxn], suf1[maxn], suf2[maxn];
vector<array<ll, 3>> V;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) c[1] = 1, d[1] = -a[i];
        else c[i] = -c[i], d[i] = b[i] - a[i] - d[i];
        for (int j = i + i; j <= n; j += i) {
            c[j] += c[i], d[j] += d[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] < 0) c[i] *= -1, d[i] *= -1;
        ll lim = d[i] >= 0 ? 0 : (!c[i] ? LLONG_MAX : (-d[i] + c[i] - 1) / c[i]);
        V.push_back({lim, c[i], d[i]});
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        pre1[i] = (i ? pre1[i - 1] : 0) + V[i][1];
        pre2[i] = (i ? pre2[i - 1] : 0) + V[i][2];
    }
    for (int i = V.size() - 1; ~i; i--) {
        suf1[i] = (i + 1 < V.size() ? suf1[i + 1] : 0) + V[i][1];
        suf2[i] = (i + 1 < V.size() ? suf2[i + 1] : 0) + V[i][2];
    }
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        ll ans = 0;
        int p = lower_bound(V.begin(), V.end(), array<ll, 3>{x + 1, LLONG_MIN, LLONG_MIN}) - V.begin();
        if (p) ans += x * pre1[p - 1] + pre2[p - 1];
        ans -= x * suf1[p] + suf2[p];
        printf("%lld\n", ans);
    }
    return 0;
}