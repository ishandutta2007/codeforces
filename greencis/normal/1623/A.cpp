#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, yb, xb, yd, xd;
        cin >> n >> m >> yb >> xb >> yd >> xd;
        int dy = 1, dx = 1;
        int ans = 0;
        for (; ; ++ans) {
            if (yb == yd || xb == xd)
                break;
            if (yb + dy > n || yb + dy < 1) dy *= -1;
            if (xb + dx > m || xb + dx < 1) dx *= -1;
            yb += dy;
            xb += dx;
        }
        cout << ans << '\n';
    }
}