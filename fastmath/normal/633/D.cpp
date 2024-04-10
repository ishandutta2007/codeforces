#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map <int, int> d;
    d.reserve(1 << 20);
    for (int i = 0; i < n; ++i) ++d[a[i]];

    set <pair <int, int> > ms;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (ms.find({a[i], a[j]}) != ms.end()) {
                continue;
            }
            ms.insert({a[i], a[j]});
            vector <int> v;
            v.push_back(a[i]);
            v.push_back(a[j]);
            --d[a[i]];
            --d[a[j]];
            while (1) {
                int t = v[v.size() - 1] + v[v.size() - 2];
                int &e = d[t];
                if (!e) break;
                --e;
                v.push_back(t);
            }
            for (int e : v) ++d[e];
            ans = max(ans, (int)v.size());
        }
    }
    
    cout << ans << '\n';
    return 0;
}