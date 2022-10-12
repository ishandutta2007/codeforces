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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll p = -inf_ll, x = inf_ll, y = 0;
        sort(all(a));
        for (auto& v : a)
            if (v <= 0) {
                y++;
                cmin(x, v-p);
                p = v;
            } else {
                if (v <= x) {
                    y++; break;
                }
            }
        cout << y << "\n";
    }
}