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

const int inf = 5e8;

void solve() {
    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vt<int> stairs(cl + 2), elevators(ce + 2);
    stairs[0] = elevators[0] = -inf;
    stairs.back() = elevators.back() = inf;
    for (int i = 1; i <= cl; i++) {
        cin >> stairs[i];
    }
    for (int i = 1; i <= ce; i++) {
        cin >> elevators[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        if (x1 == x2) cout << y2 - y1 << '\n';
        else {
            auto it_stairs = upper_bound(all(stairs), y1);
            auto it_elevators = upper_bound(all(elevators), y1);

            cout << y2 - y1 + min(
                x2 - x1 + min(
                    max(*it_stairs, y2) - y2,
                    y1 - *(it_stairs - 1)
                ) * 2,
                (x2 - x1 + v - 1) / v + min(
                    max(*it_elevators, y2) - y2,
                    y1 - *(it_elevators - 1)
                ) * 2
            ) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}