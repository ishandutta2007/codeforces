#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define ITER(eid, a, b) \
    {auto& vv = price[min(a, b)][max(a, b)];\
    if (v[eid] < (int)vv.size()) { \
        v[10] = b; cur = max(cur, vv[v[eid]++] + f(v)); --v[eid]; v[10] = a; \
    }}

vector<int> price[4][4];
map<vector<short>, ll> mp;

ll f(vector<short> v) {
    ll& rf = mp[v];
    if (!rf) {
        ll cur = 0;
        if (v[10] == 0) {
            ITER(0, 0, 0)
            ITER(1, 0, 1)
            ITER(2, 0, 2)
            ITER(3, 0, 3)
        } else if (v[10] == 1) {
            ITER(1, 1, 0)
            ITER(4, 1, 1)
            ITER(5, 1, 2)
            ITER(6, 1, 3)
        } else if (v[10] == 2) {
            ITER(2, 2, 0)
            ITER(5, 2, 1)
            ITER(7, 2, 2)
            ITER(8, 2, 3)
        } else {
            ITER(3, 3, 0)
            ITER(6, 3, 1)
            ITER(8, 3, 2)
            ITER(9, 3, 3)
        }
        rf = cur + 1;
    }
    return rf - 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, z, y;
        cin >> x >> z >> y;
        --x; --y;
        if (x > y) swap(x, y);
        price[x][y].push_back(z);
    }
    for (int i = 0; i < 4; ++i) {
        while (price[i][i].size() > 1) {
            int x = price[i][i].back();
            price[i][i].pop_back();
            price[i][i].back() += x;
        }
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            sort(all(price[i][j]));
            if (price[i][j].size() > 3) {
                int cur = 0;
                while (price[i][j].size() > 3) {
                    cur += price[i][j].back(); price[i][j].pop_back();
                    cur += price[i][j].back(); price[i][j].pop_back();
                }
                cur += price[i][j].back(); price[i][j].pop_back();
                price[i][j].push_back(cur);
            }
            reverse(all(price[i][j]));
        }
    ll ans = 0;
    for (int i = 0; i < 4; ++i)
        ans = max(ans, f({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, i}));
    cout << ans << endl;
}