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

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));

    auto check = [&](int x) {
        vt<int> ans(n);
        for (int i = 0; i < x; i++) {
            ans[i * 2 + 1] = a[i];
        }

        int i = 0, p = x;
        vt<bool> used(n);
        for (; i < x * 2 + 2; i += 2) {
            while (p < n && (
                (i && a[p] <= ans[i - 1])
                || (i != n - 1 && a[p] <= ans[i + 1])
            )) {
                p++;
            }

            if (p < n) {
                ans[i] = a[p];
                used[p] = true;
                p++;
            } else break;
        }

        if (i != x * 2 + 2) return vt<int>();

        i = x * 2 + 1;
        for (int j = x; j < n; j++) {
            if (!used[j]) ans[i++] = a[j];
        }
        return ans;
    };

    int l = 0, r = (n - 1) / 2;
    while (l < r) {
        int mi = (l + r + 1) / 2;
        if (!check(mi).empty()) l = mi;
        else r = mi - 1;
    }

    cout << l << '\n';
    for (int x : check(l)) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}