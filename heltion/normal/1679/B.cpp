#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int tag = 0;
    map<int, int> mp;
    LL sum = 0;
    for (int i = 1, a; i <= n; i += 1) {
        cin >> a;
        sum += mp[i] = a; 
    }
    for (int i = 0, t, j, x; i < q; i += 1) {
        cin >> t;
        if (t == 1) {
            cin >> j >> x;
            if (mp.contains(j)) sum += x - mp[j];
            else sum += x - tag;
            mp[j] = x;
        }
        else {
            cin >> x;
            mp.clear();
            tag = x;
            sum = (LL)x * n;
        }
        cout << sum << "\n";
    }
}