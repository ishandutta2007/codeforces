#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n, n /= 2;
    if (n & 1) {
        cout << "! -1" << endl, exit(0);
    }
    auto get = [&](int x) {
        static map<int, int> mp;
        if (mp.count(x)) return mp[x];
        cout << "? " << x << endl;
        int y; cin >> y;
        cout << "? " << x + n << endl;
        int z; cin >> z;
        return mp[x] = y - z;
    };
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (!get(mid)) cout << "! " << mid << endl, exit(0);
        if (1LL * get(l) * get(mid) <= 0) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}