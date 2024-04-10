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

const int inf = 1 << 30;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<vt<int>> num(n + 1, vt<int>{-1});
    for (int i = 0; i < n; i++) {
        num[a[i]].push_back(i);
    }

    vt<int> ama(n, inf);
    for (int i = 1; i <= n; i++) {
        num[i].push_back(n);

        int dist = 1;
        for (int j = 1; j < sz(num[i]); j++) {
            dist = max(dist, num[i][j] - num[i][j - 1]);
        }

        if (dist != n + 1) ama[dist - 1] = min(ama[dist - 1], i);
    }

    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (ama[i] != inf && (!~cur || cur > ama[i])) cur = ama[i];
        cout << cur << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}