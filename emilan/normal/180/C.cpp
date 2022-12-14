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
    string s;
    cin >> s;
    int n = sz(s);

    vt<int> u(n + 1), l(n + 1);
    for (int i = 0; i < n; i++) {
        u[i + 1] = u[i] + !!isupper(s[i]);
    }
    for (int i = n; i; i--) {
        l[i - 1] = l[i] + !!islower(s[i - 1]);
    }

    int ans = n;
    for (int i = 0; i <= n; i++) {
        ans = min(n - u[i] - l[i], ans);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}