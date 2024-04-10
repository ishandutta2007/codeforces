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

typedef long double ld;

const int N = 2e5+5;
ld t[N], p[N], q[N], s[N], a[N], b[N];

ld f(int i, int j) {
    return s[j]-s[i-1]-(q[j]-q[i-1])*p[i-1];
}

void dfs(int l, int r, int x, int y) {
    if (l > r) return;
    int m = (l+r)/2, z = 0;
    b[m] = 1e18;
    for (int i = x; i <= min(m, y); i++) {
        ld c = a[i-1]+f(i, m);
        if (c < b[m]) b[m] = c, z = i;
    }
    dfs(l, m-1, x, z), dfs(m+1, r, z, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        p[i] = t[i]+p[i-1];
        q[i] = 1/t[i]+q[i-1];
        s[i] = s[i-1]+p[i]/t[i];
    }
    fill(a+1, a+n+1, 1e18);
    for (int j = 0; j < k; j++)
        dfs(1, n, 1, n), copy(b, b+n+1, a);
    cout << setprecision(25) << a[n] << "\n";
}