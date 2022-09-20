#include "bits/stdc++.h"

using namespace std;

const int N = 200200;
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto get = [&](int l, int r) -> int {
            int s = 0;
            cout << "? " << l << " " << r << endl;
            for (int i = l; i <= r; i++) {
                int x;
                cin >> x;
                s += (x >= l && x <= r);
            }
            return s % 2;
        };
        int res = 1;
        for (int i = 14; i >= 0; i--) {
            if (res + (1 << i) - 1 <= n && !get(res, res + (1 << i) - 1)) {
                res += (1 << i);
            }
        }
        cout << "! " << res << endl;
    }
}