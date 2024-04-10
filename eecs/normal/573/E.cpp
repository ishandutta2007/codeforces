#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010, B = 300;
int n, bel[maxn], bl[maxn], br[maxn], id[maxn], used[maxn], cur[maxn];
ll ans, sum, k[maxn], a[maxn], b[maxn], inc[maxn];
vector<int> Q[maxn / B + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), b[i] = a[i];
        br[bel[i] = (i - 1) / B + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    auto build = [&](int i) {
        Q[i].clear(), cur[i] = 0;
        auto chk = [&](int i, int j, int k) {
            ll x1 = a[j] - a[i], y1 = b[j] - b[i];
            ll x2 = a[k] - a[i], y2 = b[k] - b[i];
            return x1 * y2 >= x2 * y1;
        };
        for (int $ = bl[i]; $ <= br[i]; $++) {
            int j = id[$];
            if (used[j]) continue;
            while (Q[i].size() > 1 && chk(Q[i][Q[i].size() - 2], Q[i].back(), j)) Q[i].pop_back();
            Q[i].push_back(j);
        }
    };
    auto calc = [&](int i) {
        if (Q[i].empty()) return make_pair(LLONG_MIN, 0);
        auto eval = [&](int p) { return k[i] * a[p] + b[p]; };
        while (cur[i] + 1 < Q[i].size() && eval(Q[i][cur[i]]) < eval(Q[i][cur[i] + 1])) cur[i]++;
        return make_pair(eval(Q[i][cur[i]]) + inc[i], Q[i][cur[i]]);
    };
    iota(id + 1, id + n + 1, 1);
    for (int k = 1; k <= bel[n]; k++) {
        stable_sort(id + bl[k], id + br[k] + 1, [&](int x, int y) { return a[x] < a[y]; });
        build(k);
    }
    for (int $ = 1; $ <= n; $++) {
        pair<ll, int> mx = {LLONG_MIN, 0};
        for (int i = 1; i <= bel[n]; i++) mx = max(mx, calc(i));
        ans = max(ans, sum += mx.first);
        int p = mx.second;
        for (int i = 1; i < bel[p]; i++) inc[i] += a[p];
        for (int i = bl[bel[p]]; i < p; i++) b[i] += a[p];
        for (int i = p + 1; i <= br[bel[p]]; i++) b[i] += a[i];
        for (int i = bel[p] + 1; i <= bel[n]; i++) k[i]++;
        used[p] = 1, build(bel[p]);
    }
    printf("%lld\n", ans);
    return 0;
}