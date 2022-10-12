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

set<int, greater<>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; x ^= a;
        int y = x;
        for (int z : s) y = min(y, z^y);
        debug(x, y);
        if (y) s.insert(y);
    }
    cout << (x == 0 ? -1 : int(s.size())) << "\n";
}