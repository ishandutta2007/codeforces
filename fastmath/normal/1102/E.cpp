#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200001;
const int MOD = 998244353;
int a[N];
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
set <pair <int, int> > ms;
void add(int l, int r) {
    //cout << "add " << l << ' ' << r << '\n';
    while (ms.size() && ms.begin()->first <= r) {
        r = max(r, ms.begin()->second);
        ms.erase(ms.begin());
    }   
    ms.insert({l, r});
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map <int, int> d;
    for (int i = n - 1; i >= 0; --i) {
        if (d.find(a[i]) == d.end()) {
            d[a[i]] = i;
        }   
        add(i, d[a[i]]);
    }   
    int ans = 1;    
    for (int i = 0; i < (int)ms.size() - 1; ++i) {
        ans = mod(ans << 1);
    }   
    cout << ans << '\n';
    #ifdef HOME
        cout << "TIME: " << (double)clock() / CLOCKS_PER_SEC << '\n';  
    #endif
}