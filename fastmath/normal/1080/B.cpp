#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int n) {
    int t = (n + 1) >> 1;
    int sum = t * t;
    return -sum + (n * (n + 1) / 2 - sum);
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << '\n';
    }   

    return 0;
}