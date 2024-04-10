#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 200005, BITS = 9, S = 1 << BITS, MASK = S - 1, CNT = (MX + S - 1) / S;

struct Upd {
    int pos, val, t;
    Upd(int pos, int val, int t) : pos(pos), val(val), t(t) {}
    Upd() {}
};

int n, m, q;
int a[MX], ord[MX];
int val[MX], whole[CNT], mx[CNT][CNT], wh[CNT][CNT];
vector<Upd> upd[CNT];
vector<vector<int> > save[CNT];
int bFrom[MX], bTo[MX], bInd[2], bMx[2], nbMx[2], uFrom[MX], uTo[MX];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] > a[rhs];
}

int calcMx(int block) {
    int ret = 0;
    int from = block << BITS;
    int to = min(n - m, (block << BITS) | MASK);
    for (int k = from; k <= to; ++k)
        ret = max(ret, val[k] + whole[k >> BITS]);
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    for (int i = 0; ; ++i) {
        if (!(i & MASK)) {
            int cur = i >> BITS;
            REP(j, n) {
                mx[cur][j >> BITS] = max(mx[cur][j >> BITS], val[j] + whole[j >> BITS]);
            }
            REP(j, CNT) wh[cur][j] = whole[j];
        }
        if (i == n) break;
        int from = uFrom[i] = max(0, ord[i] - m + 1);
        int to = uTo[i] = min(n - m, ord[i]);
        bInd[0] = from >> BITS, bInd[1] = to >> BITS;
        REP(j, 2) bMx[j] = calcMx(bInd[j]);
        for (int j = from; j <= to; ) {
            if (!(j & MASK) && j + S - 1 <= to) {
                ++whole[j >> BITS];
                j += S;
            } else {
                ++val[j];
                ++j;
            }
        }
        REP(j, 2) nbMx[j] = calcMx(bInd[j]);
        bFrom[i] = from >> BITS;
        bTo[i] = to >> BITS;
        if (nbMx[0] == bMx[0]) ++bFrom[i];
        if (nbMx[1] == bMx[1]) --bTo[i];
        if ((from & MASK) || to - from < MASK) upd[from >> BITS].pb(Upd(from & MASK, +1, i));
        if ((to & MASK) != MASK || to - from < MASK) {
            if ((from >> BITS) != (to >> BITS)) upd[to >> BITS].pb(Upd(0, +1, i));
            upd[to >> BITS].pb(Upd((to & MASK) + 1, -1, i));
        }
    }
    REP(i, CNT) if ((int)upd[i].size() >= S) {
        vector<int> tmp(S + 1, 0);
        REP(j, upd[i].size()) {
            tmp[upd[i][j].pos] += upd[i][j].val;
            if ((j & MASK) == MASK)
                save[i].pb(tmp);
        }
    }
    scanf("%d", &q);
    int ans = 0;
    REP(query, q) {
        int from, to, qual;
        scanf("%d%d%d", &from, &to, &qual), --from, --to, qual ^= ans;
        int lo = -1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a[ord[mid]] < qual)
                hi = mid - 1;
            else
                lo = mid;
        }
        if (lo == -1) {
            printf("%d\n", m);
            ans = m;
            continue;
        }
        qual = lo;
        bInd[0] = from >> BITS, bInd[1] = to >> BITS;
        ans = 0;
        REP(i, 2) {
            if (i == 1 && bInd[0] == bInd[1]) break;
            int cur = bInd[i];
            lo = 0, hi = (int)upd[cur].size();
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (upd[cur][mid].t > qual)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            vector<int> tmp;
            if ((lo >> BITS) > 0) tmp = save[cur][(lo >> BITS) - 1];
            else tmp.assign(S + 1, 0);
            for (int j = lo & (~MASK); j < lo; ++j)
                tmp[upd[cur][j].pos] += upd[cur][j].val;
            int va = wh[qual >> BITS][cur];
            for (int i = qual & (~MASK); i <= qual; ++i) if (uFrom[i] <= (cur << BITS) && uTo[i] >= (cur << BITS) + MASK)
                ++va;
            REP(j, S) {
                va += tmp[j];
                if (((cur << BITS) | j) >= from && ((cur << BITS) | j) <= to)
                    ans = max(ans, va);
            }
        }
        int wfrom = from >> BITS;
        int wto = to >> BITS;
        if ((from & MASK) || to - from < S) ++wfrom;
        if ((to & MASK) != MASK || to - from < S) --wto;
        vector<int> tmp(CNT + 1, 0);
        int wqual = qual >> BITS;
        REP(i, CNT) tmp[i] = mx[wqual][i];
        for (int i = CNT - 1; i >= 1; --i) tmp[i] -= tmp[i - 1];
        for (int i = wqual << BITS; i <= qual; ++i) if (bTo[i] >= bFrom[i]) {
            ++tmp[bFrom[i]];
            --tmp[bTo[i] + 1];
        }
        int cur = 0;
        REP(i, CNT) {
            cur += tmp[i];
            if (i >= wfrom && i <= wto)
                ans = max(ans, cur);
        }
        ans = m - ans;
        printf("%d\n", ans);
    }
    return 0;
}