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

ll t = 1, n, m, ans, a[MN], sum[MN], pref[MN], suf[MN], rid[MN];
vector<int> st[MN];
vector<int> id;

bool can(int pi, int sj) {
    sj = id[sj];
    return sum[sj] <= a[pi] * st[sj].size();
}


set<int> ncanl, ncanr;

int ok(int sj, int s) {
    int lb = rid[sj];
    
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        if ((sum[sj] - st[sj][s]) * st[id[mid]].size() > sum[id[mid]] * (st[sj].size() - 1)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int rb = l;

    trace2(sj, s, lb, rb);

    if (rb > lb) rb--;
    if (lb <= rb) {
        bool possib = (lb ? pref[lb-1] : true) && suf[rb+1];
        auto lbd = ncanr.lower_bound(lb);
        if (lbd != ncanr.end() && *lbd < rb) possib = false;
        if ((sum[sj] - st[sj][s]) > a[rb] * (st[sj].size() - 1))
            possib = false;
        return possib;
    } else {
        bool possib = (rb ? pref[rb-1] : true) && suf[lb + 1];
        auto lbd = ncanl.lower_bound(rb + 1);
        if (lbd != ncanl.end() && *lbd <= lb) possib = false;
        if ((sum[sj] - st[sj][s]) > a[rb] * (st[sj].size() - 1))
            possib = false;
        return possib;
    }
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0, k; i < m; i++) {
        scanf("%d", &k);
        st[i].clear(); sum[i] = 0;
        for (int j = 0, x; j < k; j++) {
            scanf("%d", &x);
            sum[i] += x;
            st[i].push_back(x);
        }
    }

    sort(a, a + n, greater<ll>());
    reverse(a, a + m);

    id.resize(m);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return sum[i] * st[j].size() < sum[j] * st[i].size();
    });
    for (int i = 0; i < m; i++)
        rid[id[i]] = i;

    pref[0] = can(0, 0);
    for (int i = 1; i < m; i++)
        pref[i] = (pref[i-1] & can(i, i));

    suf[m] = suf[m+1] = true;
    suf[m-1] = can(m-1, m-1);
    for (int i = m-2; i >= 0; i--)
        suf[i] = (suf[i+1] & can(i, i));

    ncanl.clear(); ncanr.clear();
    for (int i = 0; i + 1 < m; i++) 
        if (!can(i, i + 1))
            ncanr.insert(i);

    for (int i = 1; i < m; i++) 
        if (!can(i, i - 1))
            ncanl.insert(i);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < st[i].size(); j++)
            printf("%d", ok(i, j));
    }

    puts("");
    if(--t) goto st;
    return 0;
}