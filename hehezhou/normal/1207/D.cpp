#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
map<int, int> a, b;
map<pair<int, int>, int> ab;
pair<int, int> d[300010];
int n;
int fac[300010];
int main() {
    ios :: sync_with_stdio(0);
    cin >> n;
    fac[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> d[i].first >> d[i].second;
        fac[i] = 1ll * i * fac[i - 1] % mod;
        a[d[i].first] += 1;
        b[d[i].second] += 1;
        ab[d[i]] += 1;
    }
    sort(d + 1, d + 1 + n);
    int ans = fac[n], tmp = 1;
    for(auto i : a)
        tmp = 1ll * tmp * fac[i.second] % mod;
    ans = (ans - tmp + mod) % mod;
    tmp = 1;
    for(auto i : b)
        tmp = 1ll * tmp * fac[i.second] % mod;
    ans = (ans - tmp + mod) % mod;
    tmp = 1;
    for(auto i : ab)
        tmp = 1ll * tmp * fac[i.second] % mod;
    for(int i = 1; i < n; i++) if(d[i + 1].second < d[i].second) tmp = 0;
    ans = (ans + tmp) % mod;
    cout << ans << endl;
}