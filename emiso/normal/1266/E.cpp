#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, q, ans, a[MN], in[MN];
map<ll, ll> pqp[MN];

void rem(ll s, ll t) {
    in[pqp[s][t]]--;
    if(in[pqp[s][t]] < a[pqp[s][t]]) ans++;
    pqp[s].erase(t);
}

void add(ll s, ll t, ll u) {
    in[u]++;
    if(in[u] <= a[u]) ans--;
    pqp[s][t] = u;
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        ans += a[i];
    }

    scanf("%lld", &q);
    while(q--) {
        ll s, t, u;
        scanf("%lld %lld %lld", &s, &t, &u);

        if(pqp[s].count(t)) rem(s, t);
        if(u) add(s, t, u);

        printf("%lld\n", ans);
    }
    return 0;
}