#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kN = 1e6;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
        x--;
    }

    vector<int> sz;
    vector<bool> vis(n);
    for (int s = 0; s < n; s++) if (!vis[s]) {
        sz.emplace_back();
        for (int u = s; !vis[u]; u = p[u]) {
            vis[u] = true;
            sz.back()++;
        }
    }

    array<int, kN + 1> cnt = {};
    for (int w : sz) cnt[w]++;
    for (int w = 2; w <= kN; w++) if (cnt[w] > 2) {
        cnt[2 * w] += (cnt[w] - 1) / 2;
        cnt[w] = (cnt[w] - 1) % 2 + 1;
    }

    bitset<kN + 1> dp;
    dp[0] = true;
    for (int w = 2; w <= kN; w++) {
        if (cnt[w] == 1) {
            dp |= dp << w;
        } else if (cnt[w] == 2) {
            dp |= dp << w | dp << (2 * w);
        }
    }
    int ans_min = k + !dp[k];

    int pairs = 0, singles = 0;
    for (int w : sz) {
        pairs += w / 2;
        singles += w & 1;
    }
    int ans_max = 2 * min(pairs, k) + clamp(k - pairs, 0, singles);

    cout << ans_min << ' ' << ans_max << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}