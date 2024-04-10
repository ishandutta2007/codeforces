#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll ans;
multiset<ll> S;

int main() {
    scanf("%d", &n);
    while (n--) {
        ll w;
        scanf("%lld", &w);
        S.insert(w), S.insert(w);
        ans += w - *S.begin(), S.erase(S.begin());
    }
    printf("%lld\n", ans);
    return 0;
}