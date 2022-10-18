#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXP = 1001001;
int lp[MAXP + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(lp, lp + MAXP + 1, 0);
    for (int i = 2; i <= MAXP; ++i) {
        if (lp[i] == i) {
            for (int j = 2 * i; j <= MAXP; j += i) {
                if (lp[j] == j) {
                    lp[j] = i;
                }
            }
        }
    }

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, e;
        cin >> n >> e;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 1) x = 1;
            else if (lp[x] == x) x = 2;
            else x = 0;
            v[i] = x;
        }
        ll ans = 0;
        for (int rem = 0; rem < e; ++rem) {
            vector<int> cur;
            for (int i = rem; i < n; i += e)
                cur.push_back(v[i]);
            for (int i = 0; i < (int)cur.size(); ++i) {
                if (cur[i] == 2) {
                    int j = i - 1;
                    while (j >= 0 && cur[j] == 1)
                        --j;
                    int k = i + 1;
                    while (k < (int)cur.size() && cur[k] == 1)
                        ++k;
                    ans += ll(i - j) * ll(k - i) - 1;
                }
            }
        }
        cout << ans << '\n';
    }
}