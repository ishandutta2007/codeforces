#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int z = 3;
    while (cin >> str && str != "end") {
        auto ask = [&](int x, int y) {
            cout << "? " << x << " " << y << endl;
            string s; cin >> s;
            return s == "x";
        };
        if (ask(0, 1)) { cout << "! 1" << endl; continue; }
        int l = 2, r = 1e9, ans;
        while (l <= r) {
            int mid = min(2 * (l - 1), (l + r) / 2);
            if (ask(l - 1, mid)) r = (ans = mid) - 1;
            else l = mid + 1;
        }
        cout << "! " << ans << endl;
    }
    return 0;
}