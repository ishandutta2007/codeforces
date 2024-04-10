#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 400020

ll acs[MN], ace[MN], h[MN][2];

inline ll rnd() {
    return ((rand()<< 16) ^ rand()) & 0x7fffffff;
}

inline ll mrand() {
    return (rnd() << 30) ^ rnd();
}

ll n, sa[MN], ea[MN], sb[MN], eb[MN], p[MN];
set<ll> ps;

struct event {
    int x, t, id;
    bool operator <(const event& o) const {
        if(x == o.x) return t > o.t;
        return x < o.x;
    }
};
vector<event> ev1, ev2;

int main() {
    srand(time(NULL));
    scanf("%lld", &n);

    while(ps.size() < n) {
        ps.insert(mrand());
    }

    vector<ll> ys;
    for(int i = 0; i < n; i++) {
        p[i] = *(ps.begin());
        ps.erase(p[i]);

        scanf("%lld %lld %lld %lld", &sa[i], &ea[i], &sb[i], &eb[i]);
        ys.push_back(sa[i]);
        ys.push_back(ea[i]);
        ys.push_back(sb[i]);
        ys.push_back(eb[i]);
    }


    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    int mx = ys.size();
    for(int i = 0; i < n; i++) {
        sa[i] = lower_bound(ys.begin(), ys.end(), sa[i]) - ys.begin();
        ea[i] = lower_bound(ys.begin(), ys.end(), ea[i]) - ys.begin();
        sb[i] = lower_bound(ys.begin(), ys.end(), sb[i]) - ys.begin();
        eb[i] = lower_bound(ys.begin(), ys.end(), eb[i]) - ys.begin();
    }

    for(int i = 0; i < n; i++) {
        acs[sa[i]] ^= p[i];
        ace[ea[i]] ^= p[i];
    }
    for(int i = 1; i < mx; i++) {
        ace[i] ^= ace[i-1];
    }
    for(int i = mx-1; i >= 0; i--) {
        acs[i] ^= acs[i+1];
    }

    for(int i = 0; i < n; i++) {
        if(sa[i])           h[i][0] ^= ace[sa[i]-1];
        if(ea[i] < mx - 1)   h[i][0] ^= acs[ea[i]+1];
    }

    memset(acs, 0, sizeof acs);
    memset(ace, 0, sizeof ace);

    for(int i = 0; i < n; i++) {
        acs[sb[i]] ^= p[i];
        ace[eb[i]] ^= p[i];
    }
    for(int i = 1; i < mx; i++) {
        ace[i] ^= ace[i-1];
    }
    for(int i = mx-1; i >= 0; i--) {
        acs[i] ^= acs[i+1];
    }

    for(int i = 0; i < n; i++) {
        if(sb[i])           h[i][1] ^= ace[sb[i]-1];
        if(eb[i] < mx - 1)   h[i][1] ^= acs[eb[i]+1];

        if(h[i][0] != h[i][1]) {
            puts("NO");
            exit(0);
        }
    }

    puts("YES");
    return 0;
}