#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int b, w;
        cin >> b >> w;

        if (w > 3 * b + 1 || b > 3 * w + 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        auto print = [&](int x, int y) { cout << x << ' ' << y << '\n'; };

        int x;
        if (w >= b) {
            x = 3;
        } else {
            x = 2;
            swap(w, b);
        }

        for (int i = 0; i < b * 2; i++) {
            print(x, i + 1);
        }

        if (w > b) {
            print(x, 2 * b + 1);

            w -= b + 1;
            for (int i = 0; i < b && w > 0; i++, w--) {
                print(x - 1, 2 * i + 2);
            }
            for (int i = 0; i < b && w > 0; i++, w--) {
                print(x + 1, 2 * i + 2);
            }
        }
    }
}