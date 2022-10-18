#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[101010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, l;
        cin >> n >> l;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        a[0] = 0;
        a[n + 1] = l;

        ld xa = 0, xb = l;
        ld va = 1, vb = 1;
        int pa = 1, pb = n;
        ld ans = 0;
        while (true) {
            if (a[pa] > a[pb]) {
                ans += (xb - xa) / (va + vb);
                break;
            }
            ld ta = (a[pa] - xa) / va;
            ld tb = (xb - a[pb]) / vb;
            if (ta <= tb) {
                ans += ta;
                xa += ta * va;
                xb -= ta * vb;
                ++va;
                ++pa;
            } else {
                ans += tb;
                xa += tb * va;
                xb -= tb * vb;
                ++vb;
                --pb;
            }
        }
        cout << setprecision(17) << fixed << ans << '\n';
    }
}