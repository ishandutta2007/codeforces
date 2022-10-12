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

const int N = 5e5+5, L = 1e6+5;
int _n, _a[N], u[N], v[N];

vector<int> d[L];
int f[L];

ll solve(int* a, int n) {

    if (n == 1)
        return 1;

    int m = n/2;
    ll ans = 0;

    for (int i = m; i < n; i++) {
        u[i] = i == m ? a[i] : min(a[i], u[i-1]);
        v[i] = i == m ? a[i] : max(a[i], v[i-1]);
    }

    for (int i = m-1; i >= 0; i--) {
        u[i] = i == m-1 ? a[i] : min(a[i], u[i+1]);
        v[i] = i == m-1 ? a[i] : max(a[i], v[i+1]);
    }

    debug(vector(a, a+n));
    debug(vector(u, u+n));
    debug(vector(v, v+n));

    int l, r, p, q;

    // max and min both on left side

    r = 0;
    for (l = 1; l <= m; l++) {
        while (r < n-m && u[m+r] >= u[m-l] && v[m+r] <= v[m-l] && !(u[m+r] == u[m-l] && v[m+r] == v[m-l]))
            r++;
        if (v[m-l]%u[m-l] == 0)
            ans += r;
    }

    debug(ans);

    // max and min both on right side

    l = 0;
    for (r = 1; r <= n-m; r++) {
        while (l < m && u[m+r-1] <= u[m-l-1] && v[m+r-1] >= v[m-l-1])
            l++;
        if (v[m+r-1]%u[m+r-1] == 0)
            ans += l;
    }

    debug(ans);

    // max on left, min on right

    p = 0, q = 0;
    for (l = 1; l <= m; l++) {
        while (q < n-m && v[m+q] < v[m-l]) {
            f[u[m+q]]++;
            q++;
        }
        while (p < q && u[m+p] >= u[m-l]) {
            f[u[m+p]]--;
            p++;
        }
        for (int x : d[v[m-l]])
            ans += f[x];
    }

    while (p < q) {
        f[u[m+p]]--;
        p++;
    }

    debug(ans);

    // max on right, min on left

    p = 0, q = 0;
    for (r = 1; r <= n-m; r++) {
        while (q < m && v[m-q-1] < v[m+r-1]) {
            f[u[m-q-1]]++;
            q++;
        }
        while (p < q && u[m-p-1] >= u[m+r-1]) {
            f[u[m-p-1]]--;
            p++;
        }
        for (int x : d[v[m+r-1]])
            ans += f[x];
    }

    while (p < q) {
        f[u[m-p-1]]--;
        p++;
    }

    debug(ans);

    return ans + solve(a, m) + solve(a+m, n-m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 1; i < L; i++)
        for (int j = i; j < L; j += i)
            d[j].pb(i);

    int t; cin >> t;
    while (t--) {
        cin >> _n;
        for (int i = 0; i < _n; i++)
            cin >> _a[i];
        cout << solve(_a, _n) << "\n";
    }
}