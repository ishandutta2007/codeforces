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
    map<int, vt<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int mx = 0;
    vt<pii> cur{{0, -1}};
    for (auto &r : pos) {
        auto &numPos = r.se;
        sort(all(numPos));

        int curMx = 0;
        for (auto &i : cur) {
            auto it = upper_bound(all(numPos), i.se);
            if (it == numPos.begin()) curMx = max(curMx, i.fi);
            else mx = max(mx, i.fi + (int)distance(it, numPos.end()));
        }
        cur.clear();
        curMx += sz(numPos);
        cur.emplace_back(curMx, numPos.back());
        mx = max(mx, curMx);

        for (int i = sz(numPos) - 2; i >= 0; i--) {
            cur.emplace_back(i + 1, numPos[i]);
        }
    }
    cout << n - mx << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}