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
    int n, m; cin >> n >> m;
    int x = 0, y = 0, c = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char a; cin >> a;
            if (a == 'B') c++, x += i, y += j;
        }
    cout << x/c << " " << y/c << "\n";
}