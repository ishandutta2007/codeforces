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
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> stk;
        vector<int> x(n); iota(all(x), 0);
        sort(all(x), [&](int i, int j){ return a[i] < a[j]; });
        vector<ll> m(n), mm(n);
        for (int i = 0; i < n; i++)
            m[i] = i == 0 ? b[x[i]] : max(b[x[i]], m[i-1]);
        for (int i = n-1; i >= 0; i--) {
            mm[i] = i == n-1 ? b[x[i]] : min(b[x[i]], mm[i+1]);
        }
        debug(x);
        debug(m);
        debug(mm);
        int j = -1;
        for (int i = n-1; i >= 1; i--) {
            if (mm[i] > m[i-1]) {
                j = i; break;
            }
        }
        debug(j);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[x[i]] = i >= j;
        for (int i = 0; i < n; i++)
            cout << (ans[i] ? 1 : 0);
        cout << "\n";
    }
}