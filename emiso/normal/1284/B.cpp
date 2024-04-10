#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a, mini[MN], maxi[MN], ok;

struct event {
    int x, t;
    bool operator <(const event& o) const {
        if(x == o.x) return t < o.t;
        return x < o.x;
    };
};
vector<event> ev;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        int k = 0, asc = 0;
        mini[i] = 1000000000LL;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%lld", &a);

            if(j && a > mini[i]) {
                asc = true;
            }

            mini[i] = min(mini[i], a);
            maxi[i] = max(maxi[i], a);
        }

        if(asc) {
            ok++;
        } else {
            ev.push_back({mini[i]  , 0});
            ev.push_back({maxi[i]-1, 1});
        }
    }

    sort(ev.begin(), ev.end());
    ans += ok * n * 2LL - ok * ok;

    ll open = 0, closed = 0;
    for(event e : ev) {
        if(e.t == 1) {
            closed++;
            ans += open;
        } else {
            open++;
        }
    }

    printf("%lld\n", ans);
    return 0;
}