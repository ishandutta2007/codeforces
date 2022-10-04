#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int l, r;
    cin >> l >> r;
    for (int x = l; x <= r; ++x) {
        vector <int> d(10);
        int cr = x;
        bool fl = true;
        while (cr > 0) {
            if (d[cr % 10]) {
                fl = false;
                break;
            }
            d[cr % 10] = 1;
            cr /= 10;
        }
        if (fl) {
            cout << x << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}