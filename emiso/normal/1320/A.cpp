#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
map<ll, ll> val;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        val[a[i] - i] += a[i];
    }

    for(auto tt : val) {
        ans = max(ans, tt.second);
    }

    printf("%lld\n", ans);
    return 0;
}