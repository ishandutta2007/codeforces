#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

struct seg {
    int l, r;
};

int t, n, m;

vector<int> p(n);
vector<vector<seg>> to_l(n), to_r(n);
vector<vector<ll>> dp, pref, suf;

inline ll lcost(int i, int s) {
    if(s == 0) return 0;
    return p[i] - to_l[i][s-1].r;
}
inline ll rcost(int i, int s) {
    if(s == 0) return 0;
    return to_r[i][s-1].l - p[i];
}

ll solve(int i, int seg);

ll gpref(int i, int r) {
    if(r == 0) return solve(i+1, (int)to_l[i+1].size());
    ll &x = pref[i][r];
    if(x != -1) return x;
    x = min(2*rcost(i, r) + solve(i+1, (int)to_l[i+1].size()-r),
            gpref(i, r-1));
    return x;
}

ll gsuf(int i, int r) {
    if(r > (int)to_r[i].size()) return INT_MAX;
    ll &x = suf[i][r];
    if(x != -1) return x;
    x = min(rcost(i, r) + solve(i+1, (int)to_l[i+1].size()-r),
            gsuf(i, r+1));
    return x;
}

ll solve(int i, int seg) {
    ll L = lcost(i, seg);
    if(i == n-1) {
        ll R = rcost(i, (int)to_r[i].size());
        return 2*min(L, R) + max(L, R);
    }
    
    ll &x = dp[i][seg];
    if(x != -1) return x;
    x = INT_MAX;

    int l = 0, r = (int)to_r[i].size(), m;
    while(l < r) {
        m = (l + r + 1) / 2;
        if(rcost(i, m) < L) l = m;
        else r = m - 1;
    }

    x = min(L + gpref(i, l),
            2*L + gsuf(i, l + 1));
    return x;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        p = vector<int>(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        sort(p.begin(), p.end());

        vector<seg> segs1, segs;
        for(int i = 0, l, r; i < m; i++) {
            scanf("%d %d", &l, &r);

            auto it = lower_bound(p.begin(), p.end(), l);
            if(it == p.end() || *it > r) {
                segs1.push_back({l, r});
            }
        }
        sort(segs1.begin(), segs1.end(), [&](seg& a, seg& b) {
            if(a.r != b.r) return a.r < b.r;
            return a.l > b.l;
        });

        set<int> st;
        for(auto s : segs1) {
            if(st.lower_bound(s.l) == st.end()) {
                st.insert(s.l);
                segs.push_back(s);
            }
        }

        m = (int)segs.size();
        to_l = to_r = vector<vector<seg>>(n);
        for(int pi = -1, si = 0; si < m; si++) {
            while(pi + 1 < n && segs[si].l >= p[pi+1]) pi++;
            if(pi >= 0) to_r[pi].push_back(segs[si]);
        }
        for(int pi = n, si = m-1; si >= 0; si--) {
            while(pi > 0 && segs[si].r <= p[pi-1]) pi--;
            if(pi < n) to_l[pi].push_back(segs[si]);
        }

        dp = pref = suf = vector<vector<ll>>(n);
        for(int i = 0; i < n; i++) dp[i].resize(to_l[i].size() + 1, -1);
        for(int i = 0; i < n; i++) pref[i].resize(to_r[i].size() + 1, -1);
        for(int i = 0; i < n; i++) suf[i].resize(to_r[i].size() + 1, -1);


        printf("%lld\n", solve(0, (int)to_l[0].size()));
    }
    return 0;
}