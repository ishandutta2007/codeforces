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

const int N = 2e5+5;
ll a[N], sm[N], n, k;

bool exists(int x) {
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += (a[i-1] >= x ? 1 : -1);
        sm[i] = min(sm[i-1], s);
        if (i >= k && s-sm[i-k] > 0) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = 1;
    for (int i = 1<<30; i > 0; i /= 2)
        if (x+i <= n && exists(x+i)) x += i;
    cout << x << "\n";
}