#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = int64_t;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    // sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        a[i] -= i;
    }
    i64 ans = 0;
    multiset<i64> slopes;
    slopes.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        slopes.insert(a[i]);
        auto last = *slopes.rbegin();
        if (last > a[i]) {
            ans += last - a[i];
            slopes.erase(slopes.find(last));
            slopes.insert(a[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}