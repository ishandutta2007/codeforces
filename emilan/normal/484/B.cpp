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

const int maxm = 2e6 + 5;
int m[maxm];

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = sz(a);

    for (int i = 0, p = 0; i < maxm; i++) {
        while (p < n && a[p] == i) p++;
        if (p) m[i] = a[p - 1];
    }

    int ans = 0;
    for (int x : a) {
        for (int i = x - 1; i < maxm; i += x) {
            if (m[i] >= x) ans = max(ans, m[i] % x);
        }
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