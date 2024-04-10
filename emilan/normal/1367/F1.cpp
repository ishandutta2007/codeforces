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
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int mx = 0, cur = 0, p = -1;
    for (auto &i : pos) {
        if (p < i.se) cur++;
        else {
            mx = max(mx, cur);
            cur = 1;
        }
        p = i.se;
    }
    mx = max(mx, cur);
    cout << n - mx << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}