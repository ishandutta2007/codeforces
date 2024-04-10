#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int n, fenw[100100];
inline void upd(int x, int val) {
    for (; x < n; x |= x + 1)
        fenw[x] += val;
}
inline int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += fenw[x];
    return ans;
}
inline int get(int L, int R) {
    if (L > R)
        return 0;
    return get(R) - get(L - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        string s, t;
        cin >> n >> s >> t;
        fill_n(fenw, n, 0);
        vector<queue<int>> q(26);
        for (int i = 0; i < n; ++i) {
            q[s[i] - 'a'].push(i);
        }
        auto getRealPos = [&](int x) {
            return x + get(x + 1, n - 1);
        };
        ll ans = 1e18;
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            int toLess = 1e9;
            for (int j = 0; j < t[i] - 'a'; ++j) {
                if (!q[j].empty()) {
                    int x = getRealPos(q[j].front());
                    toLess = min(toLess, x - i);
                }
            }
            if (toLess != 1e9)
                ans = min(ans, cur + toLess);
            if (q[t[i] - 'a'].empty())
                break;
            int genuinePos = q[t[i] - 'a'].front();
            int x = getRealPos(genuinePos);
            q[t[i] - 'a'].pop();
            upd(genuinePos, 1);
            cur += x - i;
        }
        if (ans == (ll)1e18)
            ans = -1;
        cout << ans << '\n';
    }
}