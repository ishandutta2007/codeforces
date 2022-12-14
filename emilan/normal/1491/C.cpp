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

    ll ans = 0;
    vt<int> s(n);
    for (int i = 0; i < n - 1; i++) {
        int p = n - i - 1;
        if (a[i] > p) {
            if (a[i] - s[i] > p) {
                a[i] -= s[i];
                s[i] = 0;
            } else {
                s[i] -= a[i] - p;
                a[i] = p;
            }

            ans += a[i] - p;
            a[i] = p;
        }

        ans += max(a[i] - s[i] - 1, 0);

        if (s[i] > a[i] - 1) {
            s[i + 1] += s[i] - a[i] + 1;
        }

        for (int j = a[i]; j > 1; j--) {
            s[i + j]++;
        }
    }

    ans += max(a[n - 1] - s[n - 1] - 1, 0);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}