#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    function<int(int, int, int)> f = [&](int l, int r, int p) {
        if (l > r) return 0;

        vt<int> minIdx{l};
        for (int i = l + 1; i <= r; i++) {
            int mn = minIdx.back();
            if (a[i] < a[mn]) minIdx.clear();
            if (a[i] <= a[mn]) minIdx.push_back(i);
        }

        int mn = a[minIdx[0]], ret1 = r - l + 1, ret2 = mn - p;
        if (sz(minIdx) != r - l + 1) {
            ret2 += f(l, minIdx[0] - 1, mn);
            ret2 += f(minIdx.back() + 1, r, mn);
            for (int i = 1; i < sz(minIdx); i++)
                ret2 += f(minIdx[i - 1] + 1, minIdx[i] - 1, mn);
        }

        return min(ret1, ret2);
    };

    cout << f(0, n - 1, 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}