#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN];
map <int, int> d;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[a[i]] = i + 1;
    }
    
    if ((int)d.size() < k) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        int h = 0;
        for (pair <int, int> elem : d) {
            cout << elem.second << ' ';
            ++h;
            if (h == k) break;
        }
    }

    return 0;
}