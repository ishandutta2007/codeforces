#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

vt<ll> inv1(30), inv2(30);

bool compare_bit(int x, int y, int bit) {
    return (x >> bit) <= (y >> bit);
}

ll count_inv(vt<int> &a, int bit) {
    if (sz(a) < 2) return 0;
    int n = sz(a),
        mi = n / 2;
    vt<int> a_left(a.begin(), a.begin() + mi),
            a_right(a.begin() + mi, a.end());
    ll ret = count_inv(a_left, bit) + count_inv(a_right, bit);

    for (int i = 0, li = 0, ri = 0, ln = mi, rn = n - mi; i < n; i++) {
        if (ri == rn ||
                (li != ln && compare_bit(a_left[li], a_right[ri], bit))) {
            a[i] = a_left[li++];
        } else {
            a[i] = a_right[ri++];
            ret += ln - li;
        }
    }

    return ret;
}

void check(vt<int> a, int bit = 29) {
    inv1[bit] += count_inv(a, bit);
    vt<int> a0, a1;
    for (int i : a) {
        if (i & 1 << bit) a1.push_back(i);
        else a0.push_back(i);
    }
    inv2[bit] += ll(sz(a0)) * sz(a1);

    if (bit) {
        if (!a1.empty()) check(a1, bit - 1);
        if (!a0.empty()) check(a0, bit - 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    check(a);

    int bit = 0;
    ll iv_cnt = 0;
    for (int i = 0; i < 30; i++) {
        if (inv1[i] > inv2[i] / 2) {
            bit |= 1 << i;
            iv_cnt += inv2[i] - inv1[i];
        } else iv_cnt += inv1[i];
    }

    cout << iv_cnt << ' ' << bit << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}