#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll q, a[300030], c[300030], par[20][300030];

int main() {
    scanf("%lld %lld %lld", &q, &a[0], &c[0]);
    for(int i = 1; i <= q; i++) {
        ll t, p, v, w;
        scanf("%lld", &t);
        if(t == 1) {
            scanf("%lld %lld %lld", &p, &a[i], &c[i]);
            par[0][i] = p;
            for(int b = 1; b < 20; b++)
                par[b][i] = par[b-1][par[b-1][i]];

        } else if (t == 2) {
            scanf("%lld %lld", &v, &w);
            ll cost = 0, bought = w;
            while(w) {
                int tmp = v;
                for(int b = 19; b >= 0; b--)
                    if(a[par[b][tmp]])
                        tmp = par[b][tmp];

                if(a[tmp] == 0) break;
                if(a[tmp] >= w) {
                    cost += w * c[tmp];
                    a[tmp] -= w;
                    w = 0;
                } else {
                    cost += a[tmp] * c[tmp];
                    w -= a[tmp];
                    a[tmp] = 0;
                }
            }

            printf("%lld %lld\n", bought - w, cost);
            fflush(stdout);
        } else assert(false);
    }
    return 0;
}