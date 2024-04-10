#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i]--;
        for (int i = 0; i < n; i++)
            cin >> b[i], b[i]--;

        vector<array<int, 2>> ans;
        auto op = [&](int l, int r) {
            debug("op", l, r);
            assert(a[l] == a[r]);
            reverse(a.begin()+l+1, a.begin()+r);
            ans.pb({l, r});
        };

        if (a[0] != b[0] || a[n-1] != b[n-1]) {
            cout << "NO\n";
            continue;
        }

        bool has_solution = 1;

        debug(a);
        debug(b);

        for (int i = 1; i < n; i++) {
            if (a[i] == b[i]) continue;

            vector<int> v(n), p(n, n);
            for (int j = i; j < n; j++) {
                v[j] = p[a[j]];
                if (p[a[j]] == n) p[a[j]] = j;
            }

            debug(i);

            int d = n;
            bool ok = 0;
            for (int j = n-1; j > i; j--) {
                // debug(j, d, a[j+1], a[i-1]);
                if (b[i] == a[j] && j < n-1 && a[j+1] == a[i-1]) {
                    op(i-1, j+1);
                    ok = 1;
                    break;
                }
                if (b[i] == a[j] && d < j && a[j-1] == a[i-1]) {
                    int x = j-1, y = j+1;
                    while (v[y] >= j) y++;
                    while (a[x] != a[y]) x--;
                    op(x, y);
                    op(i-1, y-(j-1-x));
                    ok = 1;
                    break;
                }
                if (b[i] == a[j] && a[j-1] == a[i-1] && v[j] < j) {
                    op(v[j], j);
                    op(i-1, v[j]+1);
                    ok = 1;
                    break;
                }
                d = min(d, v[j]);
            }

            debug(a);
            debug(b);

            if (!ok) {
                has_solution = 0;
                break;
            }
        }

        if (has_solution) {
            cout << "YES\n" << ans.size() << "\n";
            for (auto& [l, r] : ans)
                cout << l+1 << " " << r+1 << "\n";
        } else {
            cout << "NO\n";
        }
    }
}