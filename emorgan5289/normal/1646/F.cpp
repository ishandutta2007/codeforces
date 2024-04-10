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
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n+1));
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            a[i][x]++;
        }

    debug(a);

    // for (int k = 1; k < n; k++) {
    //     debug(k);
    //     while (1) {
    //         debug(a);
    //         int c = 0;
    //         for (int i = 0; i < n; i++)
    //             if (a[i][k] > 0) c++;
    //         if (c == n) break;
    //         vector<int> p(n), v(n);
    //         for (int i = 0; i < n; i++)
    //             if (a[i][k] > 1) v[i] = 1;
    //         for (int j = 0; j < 2; j++)
    //             for (int i = 0; i < n; i++)
    //                 if (v[(i-1+n)%n] && a[i][k] > 0)
    //                     v[i] = 1;
    //         for (int i = 0; i < n; i++) {
    //             if (v[i]) p[i] = k;
    //             else {
    //                 for (int j = k+1; j <= n; j++)
    //                     if (a[i][j] > 0) {
    //                         p[i] = j;
    //                         break;
    //                     }
    //             }
    //         }
    //         debug(p, v);
    //         ans.pb(p);
    //         for (int i = 0; i < n; i++) {
    //             a[i][p[i]]--;
    //             a[(i+1)%n][p[i]]++;
    //         }
    //     }
    // }

    while (1) {
        debug(a);
        bool ok = 1;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == 0) ok = 0;
        if (ok) break;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] > 1) {
                    p[i] = j;
                    break;
                }
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
                if (p[i] == 0) p[i] = p[(i+n-1)%n];
        debug(p);
        ans.pb(p);
        for (int i = 0; i < n; i++) {
            a[i][p[i]]--;
            a[(i+1)%n][p[i]]++;
        }
    }

    vector<int> p(n);
    iota(all(p), 1);
    for (int i = 0; i < n-1; i++) {
        rotate(p.begin(), p.end()-1, p.end());
        for (int j = 0; j < i+1; j++)
            ans.pb(p);
    }

    cout << ans.size() << "\n";
    for (auto& q : ans)
        for (int i = 0; i < n; i++)
            cout << q[i] << " \n"[i == n-1];
}