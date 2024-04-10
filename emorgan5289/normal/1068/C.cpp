#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        a[u-1].pb(i); a[v-1].pb(i);
    }
    int t = 5000;
    for (int i = 0; i < n; i++) {
        if (a[i].empty()) {
            cout << "1\n" << i+1 << " " << ++t << "\n";
        } else {
            cout << a[i].size() << "\n";
            for (auto& x : a[i])
                cout << i+1 << " " << x+1 << "\n";
        }
    }
}