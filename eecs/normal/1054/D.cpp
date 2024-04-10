#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, a[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i] ^= a[i - 1];
    }
    map<int, int> mp;
    mp[0]++;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        a[i] ^= cur;
        if (mp[a[i]] < mp[a[i] ^ ((1 << K) - 1)]) {
            mp[a[i]]++;
        } else {
            mp[a[i] ^ ((1 << K) - 1)]++;
            cur ^= ((1 << K) - 1);
        }
    }
    long long ans = 1LL * n * (n + 1) / 2;
    for (auto p : mp) ans -= 1LL * p.second * (p.second - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}