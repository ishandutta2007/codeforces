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

ll n, k;
int a[1000005];

void dfs(int l, int r) {
    int m = (l+r)/2;
    if (r-l > 1) {
        if (k > 1) {
            swap(
                a[max_element(a+l, a+m)-a],
                a[min_element(a+m, a+r)-a]
            );
            k -= 2;
            dfs(l, m);
            dfs(m, r);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k; k--;
    iota(a, a+n, 1);
    dfs(0, n);
    debug(vector(a, a+n));
    if (k > 0) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n-1];
    }
}