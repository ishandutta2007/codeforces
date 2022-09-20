#include "bits/stdc++.h"

using namespace std;

const int mod = 998244353;

int n, m, sx, sy, d;

bool good(int x, int y)
{
    return abs(x - sx) + abs(y - sy) > d;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy >> d;
        if ((good(1, sy) && good(sx, m)) || (good(sx, 1) && good(n, sy))) {
            cout << n + m - 2 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}