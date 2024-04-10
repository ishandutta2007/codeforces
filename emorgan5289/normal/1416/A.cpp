#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n, -1), d(n, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x; x--;
            d[x] = max(d[x], i-p[x]);
            p[x] = i;
        }
        for (int i = 0; i < n; i++)
            d[i] = max(d[i], n-p[i]);
        vector<int> r(n+1, inf);
        for (int i = 0; i < n; i++)
            r[d[i]-1] = min(r[d[i]-1], i);
        for (int i = 0; i < n; i++) {
            if (i > 0) r[i] = min(r[i], r[i-1]);
            cout << (r[i] == inf ? -1 : r[i]+1) << " \n"[i == n-1];
        }
    }
}