#include <bits/stdc++.h>

using namespace std;

#define int long long

int getmax(int n, int c) {
    int cnt = (1ll << (n - c)) * (1ll << (n - c));
    int ans = (cnt - 1) / 3;
    int l = 1ll << (n - c);
    int add = 0;
    if (c) {
        int t = l * l - (2 * l - 1);
        int can = t * (1ll << c) * (1ll << c);
        add = (can - t) / 3;
    }
    return ans + add;
}   

int getmin(int n, int c) {
    n -= c;
    c = 0;

    int cnt = 0;
    int l = 1ll << n;
    cnt += 4 * l - 4;

    --l;
    l >>= 1;

    while (l >= 1) {
        cnt += 2 * l - 1;
        l >>= 1;
    }   

    return (cnt - 1) / 3;
}   

void solve() {
    int n, k;
    cin >> n >> k;

    if (n >= 32) {
        cout << "YES " << n - 1 << '\n';
        return;
    }   

    if (getmax(n, 0) >= k) {
        int curr = n;
        while (getmax(n, curr) < k) {
            --curr;
        }   
        if (getmin(n, curr) <= k) {
            cout << "YES " << curr << '\n';
        }
        else {
            cout << "NO\n";
        }   
    }   
    else {
        cout << "NO\n";
    }   
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}