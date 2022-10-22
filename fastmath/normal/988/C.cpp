#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

map <int, pair <int, int> > d;
int a[MAXN];

void add(int num) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    for (int i = 0; i < n; ++i) {
        int x = sum - a[i];
        if (d.find(x) != d.end()) {
            cout << "YES\n";
            cout << d[x].first << ' ' << d[x].second << '\n';
            cout << num << ' ' << i + 1 << '\n';
            exit(0);
        }   
    }
    for (int i = 0; i < n; ++i) {
        int x = sum - a[i];
        d[x] = {num, i + 1};
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        add(i + 1);
    }

    cout << "NO\n";
    return 0;
}