#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int p = n - 1;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (p >= 0 && a[p] < 2) p--;

        if (i <= p && a[i] & 1) {
            a[i]--;
            a[p] -= 2;
            ans++;
        }
    }

    for (int i = 0; i <= p; i++) {
        while (i < p && a[i] * 2 >= a[p]) {
            ans += a[p] / 2;
            a[i] -= a[p] / 2;
            p--;
        }

        if (i == p) {
            ans += a[p] / 3;
        } else {
            ans += a[i];
            a[p] -= a[i] * 2;
        }
    }

    cout << ans;
}