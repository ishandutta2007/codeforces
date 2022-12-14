#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Everything is 1-indexed internally and 0-indexed externally
struct bit {
    int n;
    vector<ll> a;

    bit(int k) : n(k), a(n + 1) {}

    bit(vector<int> &b) : n(b.size()), a(n + 1) {
        for (int i = 1; i <= n; i++) {
            a[i] += b[i - 1];
            if (int t = i + (i & -i); t <= n) {
                a[t] += a[i];
            }
        }
    }

    ll query0(int i) {
        ll r = 0;
        for (i++; i; i -= i & -i) r += a[i];
        return r;
    }

    // [l, r)
    ll query(int l, int r) {
        return query0(r - 1) - query0(l - 1);
    }

    void update(int i, ll d) {
        for (i++; i <= n; i += i & -i) a[i] += d;
    }

    // Binary search for the first a[p] that have prefix sum x in [i, n)
    // Fail -> return n
    int search(ll x) {
        int i = 0;
        for (int k = __lg(n); k >= 0; k--) {
            if (int ni = i + (1 << k); ni <= n && a[ni] < x) {
                i = ni;
                x -= a[ni];
            }
        }

        return i;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    bit b(a);
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;

        int ori = b.query(i, i + 1);
        b.update(i, x - ori);

        if (b.query(0, 1) == 0) {
            cout << 1;
        } else {
            cout << [&]() {
                for (int k = 1; k <= 30; k++) {
                    int p = b.search(1 << k);
                    if (0 < p && p < n) {
                        if (b.query0(p - 1) * 2 == b.query0(p)) return p + 1;
                    }
                }

                return -1;
            }();
        }
        cout << '\n';
    }
}