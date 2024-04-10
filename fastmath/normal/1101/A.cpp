#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
        cout << d << '\n';
    }   
    else {
        ++r;
        cout << d * ((r + d - 1) / d) << '\n';
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int q;
    cin >> q; for (int i = 0; i < q; ++i) solve();
}