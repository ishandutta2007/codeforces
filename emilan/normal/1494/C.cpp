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
    int n, m;
    cin >> n >> m;
    vt<int> b0, b1, s0, s1;
    while (n--) {
        int x;
        cin >> x;
        if (x < 0) b0.push_back(-x);
        else b1.push_back(x);
    }
    while (m--) {
        int x;
        cin >> x;
        if (x < 0) s0.push_back(-x);
        else s1.push_back(x);
    }

    auto f = [&](vt<int> &b, vt<int> &s) {
        int n = sz(b), m = sz(s);
        sort(all(b));
        sort(all(s));

        vt<int> gd(m);
        for (int i = 0, p = 0; i < m; i++) {
            for (; p < n && b[p] < s[i]; p++);

            if (p < n && b[p] == s[i]) gd[i] = 1;
        }

        queue<int> q;
        int gds = count(all(gd), 1);
        int ans = gds;
        for (int i = 0, p = 0; i < m; i++) {
            for (; p < n && b[p] <= s[i]; p++);

            q.push(s[i]);
            while (!q.empty() && q.front() + p <= s[i]) q.pop();

            gds -= gd[i];
            ans = max(sz(q) + gds, ans);
        }

        return ans;
    };

    cout << f(b0, s0) + f(b1, s1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}