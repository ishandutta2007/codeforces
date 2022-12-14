#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, u, v, w;
    cin >> n >> u >> v >> w;
    w = min(u + v, w);
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<ll> l(n + 1), r(n + 1);
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = r[i + 1] + a[i];
    }

    ll ans = 9e18;

    auto f = [&](int i, ll h) -> bool {
        ll missing = h * (i + 1) - l[i + 1];
        ll surplus = r[i + 1] - h * (n - i - 1);
        ll mv = min(missing, surplus);

        if (missing < surplus) {
            ans = min(
                mv * w + (surplus - mv) * v,
                ans
            );

            return false;
        } else {
            ans = min(
                mv * w + (missing - mv) * u,
                ans
            );

            return true;
        }
    };

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (!f(i, a[i])) m = i;
    }

    int bl = a[m], br = a[m + 1];
    while (bl + 1 < br) {
        int bm = (bl + br) / 2;
        if (!f(m, bm)) bl = bm;
        else br = bm;
    }

    f(m, bl);
    f(m, br);

    cout << ans;
}