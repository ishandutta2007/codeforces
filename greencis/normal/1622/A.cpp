#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == y + z || y == z + x || z == x + y || (x == y && z % 2 == 0)
                                                      || (x == z && y % 2 == 0)
                                                      || (z == y && x % 2 == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}