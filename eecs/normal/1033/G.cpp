#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 110;
int n, m, a[maxn];
ll v[maxn], cnt[2];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 2; i <= 2 * m; i++) {
        for (int j = 1; j <= n; j++) a[j] = v[j] % i;
        if (!(i & 1)) {
            int s = 0;
            for (int j = 1; j <= n; j++) s += a[j] / (i / 2);
            cnt[s & 1]++;
        }
        int mn = max(1, i - m), mx = (i - 1) / 2;
        vector<pair<int, int>> event = {{mn, 0}, {mx + 1, 0}};
        for (int j = 1; j <= n; j++) {
            event.emplace_back(max(mn, a[j] + 1), 1);
            int t = min(a[j], i - a[j] - 1);
            if (t >= mn) {
                event.emplace_back(mn, 2);
                event.emplace_back(t + 1, -2);
            }
            event.emplace_back(max({mn, i - a[j], a[j] / 2 + 1}), 3);
        }
        sort(event.begin(), event.end());
        int c[5] = {0, 0, 0, 0, 0};
        for (int j = 1; j < event.size(); j++) {
            if (event[j - 1].first > mx) break;
            int d = event[j].first - event[j - 1].first;
            c[abs(event[j - 1].second)] += event[j - 1].second < 0 ? -1 : 1;
            c[4] = n - c[1] - c[2] - c[3];
            if (c[2] || c[4] > 1 || c[4] == 1 && c[3] % 2 == 1) continue;
            cnt[(c[3] + c[4]) & 1] += d * 2;
        }
    }
    ll r = (1LL * m * m - cnt[0] - cnt[1]) / 2;
    printf("%lld %lld %lld %lld\n", r, r, cnt[1], cnt[0]);
    return 0;
}