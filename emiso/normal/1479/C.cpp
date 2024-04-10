#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

struct ed {
    ll u, v, c;
    ed(ll u, ll v, ll c) : u(u), v(v), c(c) {}
};

ll l, r, n = 32;
vector<ed> adj;

int main() {
    scanf("%lld %lld", &l, &r);

    int last = 32; n = last;
    adj.emplace_back(last-1, last, 1);

    for(int i = last - 2, range = 2; range < 2000000; i--, range *= 2) {
        adj.emplace_back(i, last, 1);
        for(int j = last - 1, pow = 1; j > i; j--, pow *= 2)
            adj.emplace_back(i, j, pow);
    }

    int node = 1;
    if(l > 1) {
        adj.emplace_back(1, 2, l - 1);
        r -= (l - 1);
        l = 1;
        node = 2;
    }

    adj.emplace_back(node, last, 1);
    r--;
    for(int b = 25, acum = 0; b >= 0; b--) {
        if(r & (1 << b)) {
            adj.emplace_back(node, last - 1 - b, 1 + acum);
            r -= (1 << b);
            acum += (1 << b);
        }
    }

    puts("YES");
    printf("%lld %lld\n", n, adj.size());
    for(ed e : adj) {
        printf("%lld %lld %lld\n", e.u, e.v, e.c);
    }
    return 0;
}