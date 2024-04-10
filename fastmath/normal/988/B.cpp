#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

string a[MAXN];

bool comp(string a, string b) {
    return a.size() < b.size();
}

bool check(string s, string t) {
    for (int i = 0; i + s.size() - 1 < t.size(); ++i) {
        if (t.substr(i, s.size()) == s) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, comp);

    for (int i = 0; i < n - 1; ++i) {
        if (!check(a[i], a[i + 1])) {
            cout << "NO\n";
            return 0;
        }
    }   
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << a[i] << '\n';

    return 0;
}