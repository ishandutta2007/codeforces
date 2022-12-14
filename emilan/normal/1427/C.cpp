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

struct bruh {
    int t, x, y, cnt;
};

void solve() {
    int r, n;
    cin >> r >> n;
    vt<bruh> a(n + 1);
    a[0].x = 1, a[0].y = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].x >> a[i].y;
        a[i].cnt = -1;
    }

    int before_max = -1;
    for (int i = 1; i <= n; i++) {
        if (i - r * 2 >= 0) {
            before_max = max(before_max, a[i - r * 2].cnt);
            a[i].cnt = before_max + 1;
        }
        for (int j = max(0, i - r * 2 + 1); j < i; j++) {
            if (~a[j].cnt &&
                    abs(a[i].x - a[j].x) +
                    abs(a[i].y - a[j].y) <=
                    a[i].t - a[j].t) {
                a[i].cnt = max(a[i].cnt, a[j].cnt + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, a[i].cnt);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}