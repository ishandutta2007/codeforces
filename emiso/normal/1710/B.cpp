#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, ans, x[MN], p[MN], h[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    vector<pair<ll, ll>> ev;
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &p[i]);
        ev.push_back({x[i] + 1, 0});

        ev.push_back({x[i] - p[i] + 1, 1});
        ev.push_back({x[i] + 1, -2});
        ev.push_back({x[i] + p[i] + 1, 1});
    }
    sort(ev.begin(), ev.end());
    map<ll, ll> mp;

    ll last = 0, inc = 0, cur = 0;
    for (auto e : ev) {
        cur = cur + (e.first - last) * inc;
        inc += e.second;
        if (e.second == 0) mp[e.first - 1] = cur;
        last = e.first; 
    }

    ll gr = 0, llf = INT_MIN, lr = INT_MIN;
    for (int i = 0; i < n; i++) {
        h[i] = mp[x[i]];
        if (h[i] > m) {
            h[i] -= m;
            gr = max(gr, h[i]);
            llf = max(llf, h[i] - x[i]);
            lr = max(lr, h[i] + x[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] >= gr && p[i] - x[i] >= llf && p[i] + x[i] >= lr) printf("1");
        else printf("0");
    }

    printf("\n");
    if(--t) goto st;
    return 0;
}