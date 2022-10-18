#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll p, f, cs, cw, s, w;
        cin >> p >> f >> cs >> cw >> s >> w;
        ll ans = 0;
        for (ll my_s = 0; my_s * s <= p && my_s <= cs; ++my_s) {
            ll my_w = min(cw, (p - my_s * s) / w);
            ll left_s = cs - my_s;
            ll left_w = cw - my_w;
            if (s <= w) {
                ll his_s = min(left_s, f / s);
                ll his_w = min(left_w, (f - his_s * s) / w);
                ans = max(ans, my_s + my_w + his_s + his_w);
            } else {
                ll his_w = min(left_w, f / w);
                ll his_s = min(left_s, (f - his_w * w) / s);
                ans = max(ans, my_s + my_w + his_s + his_w);
            }
        }
        cout << ans << '\n';
    }
}