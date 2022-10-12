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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<array<ll, 5>> a(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> a[i][j];
        auto cmp = [&](int i, int j) {
            int x = 0;
            for (int k = 0; k < 5; k++)
                if (a[i][k] < a[j][k]) x++;
            return x >= 3;
        };
        int b = 0;
        for (int i = 1; i < n; i++)
            if (cmp(i, b)) b = i;
        bool ok = 1;
        for (int i = 0; i < n; i++)
            if (i != b && cmp(i, b))
                ok = 0;
        debug(b, ok);
        cout << (ok ? b+1 : -1) << "\n";
    }
}