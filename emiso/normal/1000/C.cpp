#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x, y, ans[200020];

// t = 0 => abre ; t = 1 => fecha
struct ev {
    ll x, t;

    ev(ll x, ll t) : x(x), t(t) {}

    bool operator <(const ev &o) const {
        if(x == o.x) return t < o.t;
        return x < o.x;
    }
};

vector<ev> evs;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        evs.emplace_back(x, 0);
        evs.emplace_back(y+1, 1);
    }
    sort(evs.begin(), evs.end());

    ll co = 0, last = -1;
    for(ev e : evs) {
        if(last != e.x) {
            ans[co] += (e.x - last);
        }
        if(e.t == 0) co++;
        else co--;

        last = e.x;
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}