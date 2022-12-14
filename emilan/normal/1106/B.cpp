#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : c) cin >> x;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return c[i] > c[j];
    });

    while (m--) {
        int i, x;
        cin >> i >> x;
        i--;

        if (x < a[i]) {
            a[i] -= x;
            cout << ll(x) * c[i];
        } else {
            ll ans = ll(a[i]) * c[i];
            x -= a[i];
            a[i] = 0;

            while (!p.empty() && x) {
                int j = p.back();
                if (x < a[j]) {
                    a[j] -= x;
                    ans += ll(x) * c[j];
                    x = 0;
                } else {
                    ans += ll(a[j]) * c[j];
                    x -= a[j];
                    a[j] = 0;

                    p.pop_back();
                }
            }

            if (x) ans = 0;
            cout << ans;
        }
        cout << '\n';
    }
}