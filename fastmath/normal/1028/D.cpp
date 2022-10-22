#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 4e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1e9 + 7;

inline int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int l = -INF, r = INF;
set <int> ms;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        if (t == "ADD") {
            int p;
            cin >> p;
            ms.insert(p);
        }
        else {
            int p;
            cin >> p;
            auto it = ms.lower_bound(p);
            
            bool cb, cs;

            auto pr = it, nx = it;
            if (*it != *ms.begin()) --pr;
            if (*it != *ms.rbegin()) ++nx;

            cb = (*it < r);
            if (it != nx) cb &= !(*nx <= l);
            cs = (*it > l);
            if (it != pr) cs &= !(*pr >= r);

            if (!cb && !cs) {
                cout << "0\n";
                exit(0);
            }
            
            if (cb && cs) {
                ans = mod(ans << 1);
            }

            if (it != pr) {
                l = *pr;
            }
            else {
                l = -INF;
            }

            if (it != nx) {
                r = *nx;
            }
            else {
                r = INF;
            }

            ms.erase(it);
        }
    }

    if (!ms.empty()) {
        int f = 0;
        if (*ms.begin() > l) ++f;
        for (int e : ms) {
            bool c = (e < r);
            if (e != *ms.rbegin()) {
                auto nx = ms.find(e); ++nx;
                c &= (*nx > l);
            }
            f += c;
        }
        ans = mod(ans * f);
    }

    cout << ans << '\n';
    return 0;
}