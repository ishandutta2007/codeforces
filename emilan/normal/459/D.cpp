#include <bits/stdc++.h>

using namespace std;

struct BIT {
    int n;
    vector<int> a;

    BIT(int m) : n(m), a(n + 1) {}

    int query(int i) {
        int r = 0;
        for (i++; i > 0; i -= i & -i) {
            r += a[i];
        }
        return r;
    }

    void update(int i) {
        for (i++; i <= n; i += i & -i) {
            a[i]++;
        }
    }
};

vector<int> make_arr(vector<int> &a) {
    int n = a.size();

    map<int, int> m;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = ++m[ a[i] ];
    }

    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    auto l = make_arr(a);

    reverse(a.begin(), a.end());
    auto r = make_arr(a);
    reverse(r.begin(), r.end());

    BIT bit(n);
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += bit.query(l[i] - 1);
        bit.update(r[i]);
    }

    cout << ans << '\n';
}