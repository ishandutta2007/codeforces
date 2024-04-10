#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#define MOD 998244353;

ll n, k, ans, a[MN], where[MN];
vector<int> pos;

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        where[a[i]] = i;
    }

    for(int i = 0; i < k; i++) {
        ans += (n-i);
        pos.push_back(where[n-i]);
    }
    sort(pos.begin(), pos.end());

    ll howmany = 1;
    for(int i = 0; i + 1 < k; i++) {
        howmany = howmany * (1LL * pos[i+1] - pos[i]) % MOD;
    }

    printf("%lld %lld\n", ans, howmany);
    return 0;
}