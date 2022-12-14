#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct lazy_seg {
    int n;
    vector<int> a, lz, len;

    lazy_seg(const vector<int> &_a) :
            n(_a.size()), a(n << 1), lz(n, -1), len(n << 1, 1) {
        copy(_a.begin(), _a.end(), a.begin() + n);

        for (int i = n - 1; i; i--) {
            a[i] = a[i << 1] + a[i << 1 | 1];
            len[i] = len[i << 1] + len[i << 1 | 1];
        }
    }

    void apply(int i, int x) {
        a[i] = x * len[i];
        if (i < n) lz[i] = x;
    }

    void build(int i) {
        while (i >>= 1) {
            if (lz[i] == -1) {
                a[i] = a[i << 1] + a[i << 1 | 1];
            }
        }
    }

    void push(int i) {
        for (int s = __lg(i); s; s--) {
            int p = i >> s;

            if (lz[p] != -1) {
                apply(p << 1, lz[p]);
                apply(p << 1 | 1, lz[p]);
                lz[p] = -1;
            }
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;

        push(l);
        push(r - 1);

        int ans = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans += a[l++];
            if (r & 1) ans += a[--r];
        }

        return ans;
    }

    void update(int l, int r, int x) {
        int l0 = l += n;
        int r0 = r += n;

        push(l);
        push(r - 1);

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
        }

        build(l0);
        build(r0 - 1);
    }
};

bool solve() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n), f(n);

    cin >> ws;
    for (int &x : s) {
        char c;
        cin >> c;
        x = c & 1;
    }
    cin >> ws;
    for (int &x : f) {
        char c;
        cin >> c;
        x = c & 1;
    }

    vector<pii> task(q);
    for (auto &[l, r] : task) {
        cin >> l >> r;
        l--;
    }

    lazy_seg seg(f);
    reverse(task.begin(), task.end());

    for (auto [l, r] : task) {
        int cnt1 = seg.query(l, r);

        if (2 * cnt1 < r - l) {
            seg.update(l, r, 0);
        } else if (2 * cnt1 > r - l) {
            seg.update(l, r, 1);
        } else {
            return false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (seg.query(i, i + 1) != s[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << array<string, 2>{"nO", "yEs"}[solve()] << '\n';
    }
}