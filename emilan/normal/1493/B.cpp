#include <bits/stdc++.h>

using namespace std;

int mir[] ={
    0, 1, 5, -1, -1, 2, -1, -1, 8, -1
};

int main() {
    int t;
    cin >> t;

    cout << setfill('0');

    while (t--) {
        int h, m;
        cin >> h >> m;

        int x, y;
        cin >> x;
        cin.ignore(1);
        cin >> y;

        for (;;) {
            vector<int> a{x / 10, x % 10, y / 10, y % 10};

            bool ok = true;
            for (int &z : a) {
                z = mir[z];
                if (z == -1) ok = false;
            }
            reverse(a.begin(), a.end());

            if (a[0] * 10 + a[1] >= h) ok = false;
            if (a[2] * 10 + a[3] >= m) ok = false;

            if (ok) break;

            y++;
            if (y == m) y = 0, x++;
            if (x == h) x = 0;
        }

        cout << setw(2) << x << ':' << setw(2) << y << '\n';
    }
}