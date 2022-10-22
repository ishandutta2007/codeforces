#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int a[N], b[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    vector <pair <int, int> > v;
    int mn = min(a[n - 1], b[n - 1]);
    for (int i = 0; i < n; ++i) {
        if (a[i] + 1 <= min(b[i] - 1, mn)) {
            v.push_back({a[i] + 1, min(b[i] - 1, mn)});
        }
        else if (b[i] + 1 <= min(a[i] - 1, mn)) {
            v.push_back({b[i] + 1, min(a[i] - 1, mn)});
        }   
    }   
    int ans = mn + 1;
    sort(v.begin(), v.end());
    int r = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        int add = max(0ll, v[i].second - max(v[i].first, r) + 1);
        ans -= add;
        r = max(r, v[i].second + 1);
    }   
    cout << ans << '\n';
}