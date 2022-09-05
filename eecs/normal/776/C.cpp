#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll K, ans;
map<ll, int> mp;

int main() {
    scanf("%d %lld", &n, &K);
    ll pre = 0;
    mp[pre]++;
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x), pre += x;
        if (K == 1) {
            if (mp.find(pre - 1) != mp.end()) ans += mp[pre - 1];
        } else if (K == -1) {
            if (mp.find(pre - 1) != mp.end()) ans += mp[pre - 1];
            if (mp.find(pre + 1) != mp.end()) ans += mp[pre + 1];
        } else {
            for (ll z = 1; abs(z) <= n * (ll)1e9; z *= K) {
                if (mp.find(pre - z) != mp.end()) ans += mp[pre - z];
            }
        }
        mp[pre]++;
    }
    printf("%lld\n", ans);
    return 0;
}