#include <bits/stdc++.h>

using namespace std;

struct BIT {
    int n;
    vector<int> a;

    BIT(int m) : n(m), a(n + 1) {}

    int query0(int i) {
        int r = 0;
        for (i++; i > 0; i -= i & -i) {
            r += a[i];
        }
        return r;
    }

    int query(int l, int r) {
        return query0(r - 1) - query0(l - 1);
    }

    void update(int i, int d) {
        for (i++; i <= n; i += i & -i) {
            a[i] += d;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> s(a);
    sort(s.begin(), s.end());
    for (int &x : a) {
        x = lower_bound(s.begin(), s.end(), x) - s.begin();
    }

    BIT l(n), r(n);
    for (int i = 0; i < n; i++) {
        r.update(a[i], 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        r.update(a[i], -1);

        ans += (long long)l.query(a[i] + 1, n) * r.query(0, a[i]);

        l.update(a[i], 1);
    }
    cout << ans << '\n';
}