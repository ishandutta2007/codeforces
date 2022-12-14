#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kInf = INT_MAX / 2;

struct LazySeg {
    int n;
    vector<int> a, lz;

    LazySeg(int n_) : n(n_), a(2 * n, -kInf), lz(n, -kInf) {}

    void touch(int i, int x) {
        if (i < n) lz[i] = x;
        a[i] = x;
    }

    void up(int i) {
        while (i /= 2) {
            if (lz[i] == -kInf) {
                a[i] = min(a[2 * i], a[2 * i + 1]);
            }
        }
    }

    void down0(int i) {
        if (lz[i] != -kInf) {
            touch(2 * i, lz[i]);
            touch(2 * i + 1, lz[i]);
            lz[i] = -kInf;
        }
    }

    void down(int i) {
        for (int s = __lg(i); s > 0; s--) {
            down0(i >> s);
        }
    }

    int query(int l, int r) {
        l += n, r += n;
        down(l), down(r - 1);
        int ans = kInf;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = min(ans, a[l++]);
            if (r & 1) ans = min(ans, a[--r]);
        }
        return ans;
    }

    void update(int l, int r, int x) {
        int l0 = l += n, r0 = r += n;
        down(l), down(r - 1);
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) touch(l++, x);
            if (r & 1) touch(--r, x);
        }
        up(l0), up(r0 - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (auto &[w, l, r] : a) {
        cin >> l >> r >> w;
        l--, r--;
    }

    sort(ALL(a));

    int ans = kInf;
    LazySeg lzs(m - 1);
    for (auto [w, l, r] : a) {
        lzs.update(l, r, w);
        ans = min(ans, w - lzs.query(0, m - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}