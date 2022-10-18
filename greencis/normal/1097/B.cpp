#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, a[20], ok;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i= 0 ; i < n; ++i) cin >> a[i];
    for (int mask = 1 << n; mask--; ) {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += a[i] * ((mask >> i) % 2 ? 1 : -1);
        if (cur % 360 == 0) ok |= 1;
    }
    cout << (ok ? "YES" : "NO");
}