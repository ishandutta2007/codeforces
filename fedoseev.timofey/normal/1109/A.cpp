#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e7;

int cnt[2][N];
   
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cnt[0][0] = 1;
    int cur = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cur ^= a[i - 1];
        ans += cnt[i & 1][cur];
        ++cnt[i & 1][cur];
    }
    cout << ans << '\n'; 
}