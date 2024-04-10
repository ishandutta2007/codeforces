#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int w[N];
int get(int n) {
    if (n & 1) {
        return n * (n - 1) / 2 + 1;
    }   
    else {
        return n * (n - 1) / 2 + (n >> 1);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < m; ++i) cin >> tmp >> w[i];
    sort(w, w + m);
    reverse(w, w + m);
    int l = -1;
    int r = m + 1;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (get(mid) <= n) l = mid;
        else r = mid;
    }   
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        ans += w[i];
    }   
    cout << ans << '\n';
}