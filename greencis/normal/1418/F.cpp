#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int ans[200200][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(ans, -1, sizeof ans);

    int n, m;
    ll L, R;
    cin >> n >> m >> L >> R;

    // thank you, Gennady!
    for (int g = 1; g <= n; ++g) {
        for (int a1 = 1; a1 * g <= n; ++a1) {
            int a2_mn = a1 + 1;
            int a2_mx = n / g; // inequality (1)
            ll y1_mn = max<ll>(1, (L + a1 * g - 1) / (a1 * g));
            ll y1_mx = min<ll>(m, R / (a1 * g)); // inequalities (2) and (4)
            if (a2_mn <= a2_mx && y1_mn <= y1_mx) {
                // a2 * (y1 div a2) <= y1_mx
                // case 1: a2 - a1 <= (y1 div a2)
                for (int a2 = a2_mn; ans[a1 * g][0] == -1 && a2 <= a2_mx && a2 * ll(a2 - a1) <= y1_mx; ++a2) {
                    ll y1_div_a2_mn = (y1_mn + a2 - 1) / a2; // a2 must divide y1 since (a1, a2) = 1
                    ll y1_div_a2_mx = y1_mx / a2;
                    if (y1_div_a2_mn <= y1_div_a2_mx) { // can deduce y2 easily
                        ans[a1 * g][0] = y1_div_a2_mn * a2;
                        ans[a1 * g][1] = a2 * g;
                        ans[a1 * g][2] = y1_div_a2_mn * a1; // equality (3)
                    }
                }
                // case 2: (y1 div a2) < a2 - a1
                for (int y1_div_a2 = 1; ans[a1 * g][0] == -1 && y1_div_a2 * ll(a1 + y1_div_a2) < y1_mx; ++y1_div_a2) {
                    ll a2_mn_2 = max<ll>(a2_mn, (y1_mn + y1_div_a2 - 1) / y1_div_a2); // (y1 div a2) must divide y1
                    ll a2_mx_2 = min<ll>(a2_mx, y1_mx / y1_div_a2);
                    if (a2_mn_2 <= a2_mx_2) {
                        ans[a1 * g][0] = y1_div_a2 * a2_mn_2;
                        ans[a1 * g][1] = a2_mn_2 * g;
                        ans[a1 * g][2] = a1 * y1_div_a2; // equality (3)
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i][0] == -1) {
            cout << "-1\n";
        } else {
            cout << i << ' ' << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
        }
    }
}