#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int lp[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 200001; ++i)
        lp[i] = i;
    for (int i = 2; i < 200001; ++i) {
        if (lp[i] == i) {
            for (int j = i + i; j < 200001; j += i) {
                if (lp[j] == j)
                    lp[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;

    int ans = 1;
    constexpr int mod = 1'000'000'007;

    map<int, map<int, int>> mp;
    auto add = [&](int idx, int val) {
        auto& rf = mp[val];
        ++rf[idx];
        if ((int)rf.size() == n) {
            ans = ans * (ll)val % mod;
            auto it = rf.begin();
            while (it != rf.end()) {
                auto nxt = next(it);
                if (--(it->second) == 0)
                    rf.erase(it);
                it = nxt;
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x > 1) {
            int cur = lp[x];
            x /= cur;
            add(i, cur);
        }
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        --i;
        while (x > 1) {
            int cur = lp[x];
            x /= cur;
            add(i, cur);
        }
        cout << ans << '\n';
    }
}