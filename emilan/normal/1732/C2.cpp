#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

const int kS = 32;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> nonzero = {-1};
    for (int i = 0; i < n; i++) if (a[i] != 0) {
        nonzero.push_back(i);
    }
    nonzero.push_back(n);

    array<vector<int>, 30> pre;
    for (int k = 0; k < 30; k++) {
        pre[k].resize(n + 1);
        for (int i = 0; i < n; i++) {
            pre[k][i + 1] = pre[k][i] + (a[i] >> k & 1);
        }
    }

    auto query = [&](int k, int l, int r) {
        return pre[k][r] - pre[k][l];
    };

    auto nz_prev = [&](int i) {
        return *--lower_bound(ALL(nonzero), i);
    };

    auto nz_next = [&](int i) {
        return *upper_bound(ALL(nonzero), i);
    };

    while (q--) {
        int L, R;
        cin >> L >> R;
        L--;

        bool trivial = true;
        array<int, 30> freq = {};
        for (int k = 0; k < 30; k++) {
            freq[k] = query(k, L, R);
            if (freq[k] >= 2) trivial = false;
        }

        if (trivial) {
            cout << L + 1 << ' ' << L + 1 << '\n';
            continue;
        }

        L = nz_next(L - 1);
        R = nz_prev(R - 1 + 1) + 1;

        auto check = [&](int l, int r) {
            for (int k = 0; k < 30; k++) {
                if (query(k, l, r) / 2 < freq[k] / 2) return false;
            }
            return true;
        };

        int r = R;
        for (int i = 0; i < kS; r = nz_prev(r - 1) + 1, i++) {
            if (!check(L, nz_prev(r - 1) + 1)) break;
        }

        int ans_l = L, ans_r = r;
        for (int l = nz_next(L), i = 0; l < R && i < kS; l = nz_next(l), i++) {
            while (l >= r || !check(l, r)) {
                if (r == R) goto cya;
                else r = nz_next(r - 1) + 1;
            }

            if (r - l < ans_r - ans_l) {
                ans_l = l;
                ans_r = r;
            }
        }
cya:
        cout << ans_l + 1 << ' ' << ans_r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}