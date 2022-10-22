#include <bits/stdc++.h>

using namespace std;

int get(int n) {
    int ans = -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int a = 9 * i;
            int b = 6 * j;
            if (a + b <= n && (n - a - b) % 4 == 0) {
                ans = max(ans, i + j + (n - a - b) / 4);
            }
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    for (int i = 24; i < 1000; ++i) {
        bool ch = 0;
        for (int t = 0; t < 1000; ++t) {
            if (i < t * 9) continue;
            ch |= ((i - t * 9) % 4 == 0);
        }
        if (!ch) {
            cout << "KEK " << i << '\n';
            exit(0);
        }
    }
    */

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        cout << get(n) << '\n';
    }

    return 0;
}