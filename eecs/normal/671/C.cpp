#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];
long long h[maxn];
vector<int> pos[maxn];
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 1; j * j <= a[i]; j++) if (!(a[i] % j)) {
            pos[j].push_back(i);
            if (j * j < a[i]) pos[a[i] / j].push_back(i);
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        mp[i] = i;
    }
    long long ans = 0, sum = 1LL * n * (n + 1) / 2;
    auto upd = [&](int l, int r, int x) {
        auto it = prev(mp.upper_bound(l));
        if (it->second >= x) return;
        mp[l] = it->second;
        int o = l;
        while (l <= r) {
            auto it = mp.lower_bound(l);
            if (it->second >= x) break;
            auto t = next(it);
            sum += 1LL * (x - it->second) * (min(r, t->first - 1) - l + 1);
            mp.erase(it), l = min(r + 1, t->first);
        }
        mp[o] = x;
    };
    for (int i = 200000; ~i; i--) {
        h[i] = 1LL * n * (n + 1) - sum;
        if (pos[i].size() > 1) {
            if (pos[i][1] < n) upd(pos[i][1] + 1, n, n + 1);
            upd(pos[i][0] + 1, pos[i][1], pos[i].back());
            upd(1, pos[i][0], pos[i][pos[i].size() - 2]);
        }
    }
    for (int i = 1; i <= 200000; i++) {
        ans += i * (h[i] - h[i - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}