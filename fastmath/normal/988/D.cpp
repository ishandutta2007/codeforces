#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    set <int> ms;
    for (int i = 0; i < n; ++i) ms.insert(a[i]);

    for (int p = 0; p < 32; ++p) {
        int x = (1 << p);
        for (int i = 0; i < n; ++i) {
            if (ms.find(a[i] + x) != ms.end() && ms.find(a[i] + 2 * x) != ms.end()) {
                cout << "3\n";
                cout << a[i] << ' ' << a[i] + x << ' ' << a[i] + 2 * x << '\n';
                return 0;
            }
        }
    }

    for (int p = 0; p < 32; ++p) {
        int x = (1 << p);
        for (int i = 0; i < n; ++i) {
            if (ms.find(a[i] + x) != ms.end()) {
                cout << "2\n";
                cout << a[i] << ' ' << a[i] + x << '\n';
                return 0;
            }
        }
    }

    cout << "1\n";
    cout << a[0] << '\n';

    return 0;
}