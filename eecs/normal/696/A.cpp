#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
map<ll, ll> mp;

int main() {
    scanf("%d", &T);
    auto get = [&](ll x) {
        if (mp.count(x)) return mp[x];
        return 0LL;
    };
    while (T--) {
        int op; ll u, v, w;
        scanf("%d %lld %lld", &op, &u, &v);
        if (op == 1) {
            scanf("%lld", &w);
            while (u ^ v) {
                if (u > v) mp[u] += w, u >>= 1;
                else mp[v] += w, v >>= 1;
            }
        } else {
            ll s = 0;
            while (u ^ v) {
                if (u > v) s += get(u), u >>= 1;
                else s += get(v), v >>= 1;
            }
            printf("%lld\n", s);
        }
    }
    return 0;
}