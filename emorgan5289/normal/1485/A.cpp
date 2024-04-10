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
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        queue<array<int, 3>> q({{a, b, 0}});
        while (!q.empty()) {
            auto [x, y, c] = q.front(); q.pop();
            if (x == 0) {
                cout << c << "\n"; break;
            }
            q.push({x/y, y, c+1});
            q.push({x, y+1, c+1});
        }
    }
}