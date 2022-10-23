#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector d(2, vector<int>(n));
        for (auto& di : d) {
            for (int& dij : di)
                cin >> dij;
        }
        int ok = 0;
        auto check = [&](int x) {
            if (ok) return;
            vector<multiset<int>> ms(2);
            for (int i = 0; i < 2; i += 1)
                for (int dij : d[i])
                    ms[i].insert(dij);
            while (not ms[0].empty()) {
                if (*ms[0].rbegin() <= x and *ms[1].rbegin() <= x) break;
                int i = *ms[1].rbegin() > *ms[0].rbegin();
                if (not ms[i ^ 1].contains(*ms[i].rbegin() - x)) return;
                ms[i ^ 1].extract(*ms[i].rbegin() - x);
                ms[i].extract(*ms[i].rbegin());
            }
            while (not ms[0].empty()) {
                if (not ms[1].contains(x - *ms[0].begin())) return;
                ms[1].extract(x - *ms[0].begin());
                ms[0].extract(*ms[0].begin());
            }
            cout << "YES\n";
            constexpr int inf = 1'000'000'000;
            vector a(2, vector<int>(n));
            for (int _ = 0; _ < n; _ += 1) {
                int mxi = -1, mxj = -1, mx = -1;
                for (int i = 0; i < 2; i += 1)
                    for (int j = 0; j < n; j += 1)
                        if (not a[i][j]) {
                            if (d[i][j] > mx) {
                                mx = d[i][j];
                                mxi = i;
                                mxj = j;
                            }
                        }
                for (int j = 0; j < n; j += 1)  {
                    if (not a[mxi ^ 1][j] and (d[mxi ^ 1][j] + x == mx or d[mxi ^ 1][j] + mx == x)) {
                        a[mxi][mxj] = 1;
                        a[mxi ^ 1][j] = 1;
                        if (x <= inf) {
                            if (mxi == 0) cout << inf + mx << " ";
                            else cout << inf + x - mx << " ";
                        }
                        else {
                            if (mxi == 0) cout << mx << " ";
                            else cout << x - mx << " ";
                        }
                        break;
                    }
                }
            }
            cout << "\n";
            if (x <= inf)
                cout << inf << " " << inf + x << "\n";
            else cout << 0 << " " << x << "\n";
            ok = 1;
            return;
        };
        for (int i = 0; i < n; i += 1) {
            check(abs(d[0][0] - d[1][i]));
            check(abs(d[0][0] + d[1][i]));
        }
        if (not ok) cout << "NO\n";

    }
}