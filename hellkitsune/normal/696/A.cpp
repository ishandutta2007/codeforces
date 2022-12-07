#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int q;
int qt, w;
LL u, v;

LL lca(LL u, LL v, int &d1, int &d2) {
    d1 = d2 = 0;
    while (u != v) {
        if (u > v) u >>= 1, ++d1;
        if (v > u) v >>= 1, ++d2;
    }
    return u;
}

LL lca(LL u, LL v) {
    while (u != v) {
        if (u > v) u >>= 1;
        if (v > u) v >>= 1;
    }
    return u;
}

inline bool isParent(LL v, LL par) {
    while (v > par) v >>= 1;
    return v == par;
}

LL from[2000], to[2000];
int cost[2000], d[2000];
int cnt = 0;

LL solve(LL u, LL p) {
    LL res = 0;
    REP(i, cnt) {
        LL lc = lca(from[i], u);
        LL t = max(to[i], p);
        if (lc < t) continue;
        int dist = 0;
        while (lc > t) {
            lc >>= 1;
            ++dist;
        }
        res += (LL)dist * cost[i];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &q);
    REP(times, q) {
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%I64d%I64d%d", &u, &v, &w);
            int d1, d2;
            LL lc = lca(u, v, d1, d2);
            from[cnt] = u;
            to[cnt] = lc;
            d[cnt] = d1;
            cost[cnt] = w;
            ++cnt;
            from[cnt] = v;
            to[cnt] = lc;
            d[cnt] = d2;
            cost[cnt] = w;
            ++cnt;
        } else {
            scanf("%I64d%I64d", &u, &v);
            LL lc = lca(u, v);
            printf("%I64d\n", solve(u, lc) + solve(v, lc));
        }
    }
    return 0;
}