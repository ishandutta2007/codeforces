#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL t;
vector<int> le;
vector<int> ri;
int pos[300000], newPos[300000], ans[300000];

inline bool cmp(const int &lhs, const int &rhs) {
    return pos[lhs] < pos[rhs];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%I64d", &n, &m, &t);
    REP(i, n) {
        char dir;
        scanf("%d %c", pos + i, &dir), --pos[i];
        if (dir == 'L') le.pb(i);
        else ri.pb(i);
    }
    for (int x : le) newPos[x] = ((pos[x] - t) % m + m) % m;
    for (int x : ri) newPos[x] = (pos[x] + t) % m;
    if (le.empty() || ri.empty()) {
        REP(i, n) printf("%d ", newPos[i] + 1);
        printf("\n");
        return 0;
    }
    t *= 2;
    sort(le.begin(), le.end(), cmp);
    sort(ri.begin(), ri.end(), cmp);
    REP(i, le.size()) {
        int x = le[i];
        LL lo = 0, hi = t, mid;
        int ind = lower_bound(ri.begin(), ri.end(), x, cmp) - ri.begin();
        LL off = 0;
        if (--ind == -1) ind = (int)ri.size() - 1, off = m;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            LL lcnt = mid >> 1;
            LL rcnt = (mid - 1) >> 1;
            LL lfull = (i + lcnt) / (int)le.size();
            LL rfull = (rcnt + (int)ri.size() - 1 - ind) / (int)ri.size();
            if ((lfull && rfull) && (t + 4ll * m) / (lfull + rfull) < m) {
                hi = mid - 1;
                continue;
            }
            int lind = (i + lcnt) % (int)le.size();
            int rind = (ind - rcnt) % (int)ri.size();
            if (rind < 0) rind += ri.size();
            LL dist = (lfull + rfull) * m;
            dist += pos[le[lind]] - pos[ri[rind]] + off;
            if (dist <= t) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (lo & 1) {
            LL rcnt = (lo - 1) >> 1;
            int rind = (ind - rcnt) % (int)ri.size();
            if (rind < 0) rind += ri.size();
            ans[x] = newPos[ri[rind]];
        } else {
            LL lcnt = lo >> 1;
            int lind = (i + lcnt) % (int)le.size();
            ans[x] = newPos[le[lind]];
        }
    }
    REP(i, ri.size()) {
        int x = ri[i];
        LL lo = 0, hi = t, mid;
        int ind = lower_bound(le.begin(), le.end(), x, cmp) - le.begin();
        LL off = 0;
        if (ind == (int)le.size()) ind = 0, off = m;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            LL lcnt = (mid - 1) >> 1;
            LL rcnt = mid >> 1;
            LL lfull = (ind + lcnt) / (int)le.size();
            LL rfull = (rcnt + (int)ri.size() - 1 - i) / (int)ri.size();
            if ((lfull + rfull) && (t + 4ll * m) / (lfull + rfull) < m) {
                hi = mid - 1;
                continue;
            }
            int lind = (ind + lcnt) % (int)le.size();
            int rind = (i - rcnt) % (int)ri.size();
            if (rind < 0) rind += ri.size();
            LL dist = (lfull + rfull) * m;
            dist += pos[le[lind]] - pos[ri[rind]] + off;
            if (dist <= t) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (lo & 1) {
            LL lcnt = (lo - 1) >> 1;
            int lind = (ind + lcnt) % (int)le.size();
            ans[x] = newPos[le[lind]];
        } else {
            LL rcnt = lo >> 1;
            int rind = (i - rcnt) % (int)ri.size();
            if (rind < 0) rind += ri.size();
            ans[x] = newPos[ri[rind]];
        }
    }
    REP(i, n) printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}