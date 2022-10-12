#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    if (k > 3 || n < 4 || (n == 4 && k != 3) || k == 1)
        cout << "-1\n";
    else if (n == 4 || n > 4 && k == 2) {
        cout << n-1 << "\n";
        for (int i = 1; i < n; i++)
            cout << i << " " << i+1 << "\n";
    } else if (k == 3) {
        vector<pair<int, int>> a;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i%4 == (j%4)+1)
                    a.pb({i, j});
        cout << a.size() << "\n";
        for (auto& [x, y] : a)
            cout << x << " " << y << "\n";
    }
}