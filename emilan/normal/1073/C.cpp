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
    string s;
    int x, y;
    cin >> n >> s >> x >> y;

    vt<pii> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i];
        if (s[i] == 'U') p[i + 1].se++;
        if (s[i] == 'D') p[i + 1].se--;
        if (s[i] == 'R') p[i + 1].fi++;
        if (s[i] == 'L') p[i + 1].fi--;
    }
    x -= p[n].fi;
    y -= p[n].se;

    auto check = [&](int len) {
        if (!len) return !x && !y;

        for (int i = 0; i <= n - len; i++) {
            int nx = abs(x + p[i + len].fi - p[i].fi);
            int ny = abs(y + p[i + len].se - p[i].se);

            if (~(nx ^ ny ^ len) & 1 && nx + ny <= len) return true;
        }

        return false;
    };

    if (!check(n)) return void(cout << -1);

    int l = 0, r = n;
    while (l < r) {
        int mi = (l + r) / 2;
        if (check(mi)) r = mi;
        else l = mi + 1;
    }

    cout << l;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}