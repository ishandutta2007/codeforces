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

template<typename it1, typename it2>
void fixedrangermq(it1 first, it1 last, it2 result, int width) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = min(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = min(p[i], p[i-1]);
    for (int i = 0; i <= n-width; i++, result++)
        *result = min(s[i], p[i+width-1]);
}

const int N = 2e5+5;
int a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    fill(a+1, a+N, inf);
    while (k--) {
        int l, r; cin >> l >> r;
        fixedrangermq(a, a+l+1, b+r-l, r-l+1);
        copy(a, a+r-l, b);
        for (int i = 1; i < r-l; i++)
            cmin(b[i], b[i-1]);
        reverse(a, a+l+1);
        fixedrangermq(a, a+l+1, c+r-l, r-l+1);
        copy(a, a+r-l, c);
        for (int i = 1; i < r-l; i++)
            cmin(c[i], c[i-1]);
        reverse(a, a+l+1);
        for (int i = 0; i <= r; i++)
            cmin(a[i], min(b[i]+2, c[i]+1));
    }
    if (a[n] == inf)
        cout << "Hungry\n";
    else
        cout << "Full\n" << a[n] << "\n";
}