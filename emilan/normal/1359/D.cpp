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

    int mx = 0;
    for (int i = 1; i <= 30; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] > i) {
                cur = 0;
                continue;
            }
            cur += a[j];
            mx = max(cur - i, mx);
            if (cur < 0) cur = 0;
        }
    }
    cout << mx;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}