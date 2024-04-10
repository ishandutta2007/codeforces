#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int> > b;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push_back({x, i});
    }   
    sort(b.begin(), b.end());
    mt19937 rnd(time(0));
    int mn = a[0];
    shuffle(a.begin(), a.end(), rnd);
    for (int t = 0; t < (int)b.size(); ++t) {
        if (t && b[t].first == b[t - 1].first) continue;
        bool ch = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % b[t].first != a[0] % b[t].first) {
                ch = 0;
                break;
            }   
        }   
        if (ch) {
            cout << "YES\n";
            cout << mn << ' ' << b[t].second + 1 << '\n';
            exit(0);
        }   
    }   
    cout << "NO\n";
}