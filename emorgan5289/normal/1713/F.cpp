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

const int N = 1e6+5;
uint32_t n, a[N], b[N];

void solve(int l, int r) {
    if (l+1 < r) {
        int k = (r-l)/2;
        for (int i = 0; i < k; i++)
            a[l+i] ^= a[l+k+i];
        solve(l+k, r);
        solve(l, l+k);
    }
}

void ffill(int l, int r) {
    if (l+1 < r) {
        int k = (r-l)/2;
        ffill(l+k, r);
        ffill(l, l+k);
        for (int i = 0; i < k; i++)
            a[l+k+i] ^= a[l+i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    auto m = bit_ceil(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    copy(b, b+m, a);
    ffill(0, m);
    copy(b, b+m/2+1, a);
    for (int i = m/2+1; i < n; i++)
        a[i] ^= b[i-m/2];
    for (int i = n; i < m; i++)
        a[i] = b[i-m/2];
    ffill(0, m);
    for (int i = 0; i < n; i++)
        a[i] = b[i];
    for (int i = n; i < m; i++)
        a[i] ^= b[i-m/2];
    solve(0, m);
    for (int i = 0; i < n; i++)
        cout << a[i+m-n] << " \n"[i == n-1];
}