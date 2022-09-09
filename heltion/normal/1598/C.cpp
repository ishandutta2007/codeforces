#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        LL sum = 0;
        vector<LL> a(n);
        for (LL& x : a) {
            cin >> x;
            sum += x;
        }
        if ((__int128)sum * (n - 2) % n) {
            cout << "0\n";
            continue;
        }
        LL x = sum - (__int128)sum * (n - 2) / n, ans = 0;
        map<LL, int> mp;
        for (LL y : a) {
            ans += mp[x - y];
            mp[y] += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}