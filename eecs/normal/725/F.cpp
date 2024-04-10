#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll ans;
vector<ll> V;

int main() {
    scanf("%d", &n);
    while (n--) {
        ll a1, b1, a2, b2;
        scanf("%lld %lld %lld %lld", &a1, &b1, &a2, &b2);
        if (a1 + b1 >= a2 + b2) {
            ans += a1 + a2;
            V.push_back(a1 + b1), V.push_back(a2 + b2);
        } else {
            if (a1 > b2) ans += a1 - b2;
            if (b1 > a2) ans += a2 - b1;
        }
    }
    sort(V.begin(), V.end(), greater<ll>());
    for (int i = 1; i < V.size(); i += 2) {
        ans -= V[i];
    }
    printf("%lld\n", ans);
    return 0;
}