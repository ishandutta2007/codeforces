#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector <int> wh(n, -1);
    vector <vector <int>> kek;
    for (int i = 0; i + 1 < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (wh[x] == -1 && wh[y] == -1) {
            wh[x] = (int)kek.size();
            wh[y] = (int)kek.size();
            kek.push_back({});
            kek.back().push_back(x);
            kek.back().push_back(y);
        }
        else if (wh[x] == -1) {
            wh[x] = wh[y];
            kek[wh[x]].push_back(x);
        }
        else if (wh[y] == -1) {
            wh[y] = wh[x];
            kek[wh[y]].push_back(y);
        }
        else {
            if (kek[wh[x]].size() > kek[wh[y]].size()) swap(x, y);
            int l = wh[x];
            for (auto z : kek[wh[x]]) {
                wh[z] = wh[y];
                kek[wh[z]].push_back(z);
            }
            kek[l] = {};
        }
    }
    for (auto &v : kek) {
        for (auto x : v) {
            cout << x + 1 << ' ';
        }
    }
}