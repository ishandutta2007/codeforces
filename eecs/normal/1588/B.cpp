#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        map<pair<int, int>, long long> mp;
        auto ask = [&](int l, int r) {
            if (mp.count({l, r})) return mp[{l, r}];
            cout << "? " << l << " " << r << endl;
            long long z; cin >> z;
            return mp[{l, r}] = z;
        };
        int l = 2, r = n, p1, p2, p3;
        while (l <= r) {
            int mid = (l + r) / 2;
            ask(1, mid) ? r = p1 = mid - 1 : l = mid + 1;
        }
        p2 = p1 + ask(p1, n) - ask(p1 + 1, n) + 1;
        p3 = p2 + ask(p2, n) - ask(p2 + 1, n);
        cout << "! " << p1 << " " << p2 << " " << p3 << endl;
    }
    return 0;
}