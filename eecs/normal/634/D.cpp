#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, d, m, mn[20][maxn];
pair<int, int> p[maxn];

int main() {
    scanf("%d %d %d", &d, &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + m + 1);
    for (int i = 0; i <= m; i++) {
        mn[0][i] = p[i].second;
    }
    for (int k = 1; k < 20; k++) {
        for (int i = 0; i + (1 << k) - 1 <= m; i++) {
            mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + (1 << (k - 1))]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (p[i].first - p[i - 1].first > n) puts("-1"), exit(0);
    }
    if (d - p[m].first > n) puts("-1"), exit(0);
    auto calc = [&](int x) {
        int l = lower_bound(p, p + m + 1, make_pair(x - n, 0)) - p;
        int r = lower_bound(p, p + m + 1, make_pair(x, 0)) - p - 1;
        assert(l <= r);
        int k = log2(r - l + 1);
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    };
    vector<int> V = {1, d};
    for (int i = 0; i <= m; i++) {
        // V.push_back(p[i].first);
        V.push_back(min(d, p[i].first + 1));
        // V.push_back(min(d, p[i].first + n));
        V.push_back(min(d, p[i].first + n + 1));
    }
    sort(V.begin(), V.end());
    long long ans = 0;
    for (int i = 0; i < V.size(); i++) {
        ans += 1LL * calc(V[i]) * (i == V.size() - 1 ? 1 : V[i + 1] - V[i]);
    }
    printf("%lld\n", ans);
    return 0;
}