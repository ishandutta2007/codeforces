#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    if (k >= n || k >= m) {
        cout << "-1\n";
        exit(0);
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > k) break;
        int inb = a[i] + ta;
        int p = lower_bound(b, b + m, inb) - b;
        if (i + (m - p) <= k) {
            cout << "-1\n";
            exit(0);
        }   
        p += k - i;
        ans = max(ans, b[p] + tb);
    }   
    cout << ans << '\n';
}