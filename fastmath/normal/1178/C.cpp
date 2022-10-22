#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
const int MOD = 998244353;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = 0; i < n + m; ++i) {
        ans <<= 1;
        ans %= MOD;
    }
    cout << ans << '\n';
}