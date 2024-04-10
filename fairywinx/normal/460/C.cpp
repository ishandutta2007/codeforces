#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

bool check(int n, vector<int> a, int m, int w, int mid) {
    int add = 0;
    vector<int> sub(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        add -= sub[i];

        int val = max(0, mid - a[i] - add);
        add += val;
        sum += val;
        if (i + w < n)
            sub[i + w] += val;
    }
    return sum <= m;
}
 
signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = *max_element(all(a)) + m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(n, a, m, w, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}