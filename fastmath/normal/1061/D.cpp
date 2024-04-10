#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int MAXN = 1e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int n, x, y;
pair <int, int> a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);
    
    int ans = 0;
    multiset <int> ms;
    for (int i = 0; i < n; ++i) {
        int cost = x + y * (a[i].second - a[i].first);
        if (ms.empty()) {
            ans += cost;
        }
        else {
            auto t = ms.lower_bound(a[i].first);
            if (t != ms.begin()) {
                --t;
                int ncost = y * (a[i].second - *t);
                if (ncost < cost) {
                    ans += ncost;
                    ms.erase(t);
                }
                else {
                    ans += cost;
                }   
            }
            else {
                ans += cost;
            }   
        }
        ms.insert(a[i].second);
        ans = mod(ans);
    }   

    cout << ans << '\n';
    return 0;
}