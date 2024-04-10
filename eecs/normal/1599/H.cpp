#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    auto ask = [&](int x, int y) {
        static map<pair<int, int>, int> mp;
        if (mp.count({x, y})) return mp[{x, y}];
        cout << "? " << x << " " << y << endl;
        int z; cin >> z;
        return mp[{x, y}] = z;
    };
    int z = ask(1, 1);
    int l = 1, r = INF, pos;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ask(1, mid) == z - (mid - 1)) l = mid + 1;
        else r = (pos = mid) - 1;
    }
    int mn = ask(1, pos);
    int x1 = 1 + mn;
    int y1 = 1 + (z - mn);
    int y2 = INF - (ask(1, INF) - mn);
    int x2 = INF - (ask(INF, 1) - (y1 - 1));
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}