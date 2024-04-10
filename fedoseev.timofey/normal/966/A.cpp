#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

bool ok(int i, vector <int> &a) {
    return 0 <= i && i < a.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector <int> l(cl), e(ce);
    for (int i = 0; i < cl; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < ce; ++i) {
        cin >> e[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << '\n';
            continue;
        }
        int ans = 1e9;
        int rsl = lower_bound(l.begin(), l.end(), y1) - l.begin();
        int lsl = rsl - 1;
        if (ok(rsl, l)) {
            int y = l[rsl];
            ans = min(ans, abs(x1 - x2) + abs(y1 - y) + abs(y2 - y));
        }
        if (ok(lsl, l)) {
            int y = l[lsl];
            ans = min(ans, abs(x1 - x2) + abs(y1 - y) + abs(y2 - y));
        }
        int rse = lower_bound(e.begin(), e.end(), y1) - e.begin();
        int lse = rse - 1;
        if (ok(rse, e)) {
            int y = e[rse];
            ans = min(ans, (abs(x1 - x2) + v - 1) / v + abs(y1 - y) + abs(y2 - y));
        }
        if (ok(lse, e)) {
            int y = e[lse];
            ans = min(ans, (abs(x1 - x2) + v - 1) / v + abs(y1 - y) + abs(y2 - y));
        }
        cout << ans << '\n';
    }
}