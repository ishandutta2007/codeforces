#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct ev {
    ll x, c;
    bool operator <(const ev &o) const {
        return c < o.c;
    }
};

int n, k;
ll c[MN], ans, r[MN];
priority_queue<ev> p;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d", &c[i]);
    }

    int x = 0;
    for(; x <= k; x++)
        p.push(ev {x, c[x]});
    x--;

    while(!p.empty()) {
        ev t = p.top(); p.pop();
        ans += (x - t.x) * t.c;
        r[t.x] = x + 1;

        if(++x < n) p.push(ev {x, c[x]});
    }

    printf("%lld\n", ans);
    for(int i = 0; i < n; i++) {
        printf("%lld ", r[i]);
    }
    return 0;
}