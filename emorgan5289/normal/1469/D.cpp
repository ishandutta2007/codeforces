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

vector<array<int, 2>> v;

void solve(int n) {
    if (n <= 2) return;
    int x = ceil(sqrt(n));
    for (int i = x+1; i < n; i++) v.pb({i, n});
    v.pb({n, x}), v.pb({n, x});
    solve(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        v.clear(), solve(n);
        cout << v.size() << "\n";
        for (auto& [x, y] : v)
            cout << x << " " << y << "\n";
    }
}