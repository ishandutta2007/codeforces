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

#define die return void(cout << -1)

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    vt<deque<int>> apos(4);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        apos[a[i]].push_back(i);
    }

    vt<vt<int>> ans(n);
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (ans[i].empty()) {
                apos[1].pop_front();
                ans[i].push_back(y);

                y++;
            }
        } else if (a[i] == 2) {
            int y1;
            if (ans[i].empty()) {
                y1 = y;

                apos[2].pop_front();
                ans[i].push_back(y);

                y++;
            } else y1 = ans[i].back();

            if (!apos[1].empty()) {
                ans[apos[1][0]].push_back(y1);
                apos[1].pop_front();
            } else die;
        } else if (a[i] == 3) {
            int y1;
            if (ans[i].empty()) {
                y1 = y;

                apos[3].pop_front();
                ans[i].push_back(y);

                y++;
            } else y1 = ans[i].back();

            int x1 = inf;
            for (int i = 1; i <= 3; i++) {
                if (!apos[i].empty()) {
                    x1 = min(x1, apos[i][0]);
                }
            }

            if (!apos[2].empty() && x1 == apos[2][0]) {
                ans[x1].push_back(y1);
                apos[2].pop_front();
            } else if (!apos[3].empty() && x1 == apos[3][0]) {
                ans[x1].push_back(y1);
                apos[3].pop_front();
            } else if (!apos[1].empty() && x1 == apos[1][0]) {
                ans[x1].push_back(y1);
                apos[1].pop_front();
            } else die;

            ans[x1].push_back(y);
            y++;
        }
    }

    vt<pii> pr;
    for (int i = 0; i < n; i++) {
        for (int j : ans[i]) {
            pr.emplace_back(j + 1, i + 1);
            if (j >= n) die;
        }
    }
    cout << sz(pr) << '\n';
    for (pii p : pr) cout << p.fi << ' ' << p.se << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}