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

struct S {
    int from, to, col;
    S(int from, int to, int col) : from(from), to(to), col(col) {}
};

struct Cmp {
    inline bool operator()(const S &lhs, const S &rhs) const {
        return lhs.from < rhs.from;
    }
};

int n, m;
set<S, Cmp> se;
int qt, l, r, x;
vector<S> q;
LL st[1 << 18] = {}, sp[1 << 17] = {};
const int off = 1 << 17;

inline void stPush(int v, int cnt) {
    for (int i = v << 1; i <= ((v << 1) | 1); ++i) {
        st[i] += sp[v] * cnt;
        if (cnt > 1) {
            sp[i] += sp[v];
        }
    }
    sp[v] = 0;
}

int updVal;
void stAdd(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        st[v] += updVal * (LL)(R - L + 1);
        if (L != R) {
            sp[v] += updVal;
        }
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) stPush(v, (R - L + 1) >> 1);
    if (l <= mid) stAdd(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stAdd((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    st[v] = st[v << 1] + st[(v << 1) | 1];
}

LL stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r) return st[v];
    int mid = (L + R) >> 1;
    if (sp[v]) stPush(v, (R - L + 1) >> 1);
    return stGet(v << 1, L, mid, l, min(r, mid)) +
        stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) se.insert(S(i, i, i + 1));
    REP(i, m) {
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%d%d%d", &l, &r, &x), --l, --r;
            auto from = se.lower_bound(S(l, 0, 0));
            auto to = se.upper_bound(S(r, 0, 0));
            if (from->from != l) {
                --from;
            }
            for (auto it = from; it != to; ++it) {
                updVal = abs(it->col - x);
                stAdd(1, 0, off - 1, max(it->from, l), min(it->to, r));
                if (it->from < l) {
                    q.pb(S(it->from, l - 1, it->col));
                }
                if (it->to > r) {
                    q.pb(S(r + 1, it->to, it->col));
                }
            }
            q.pb(S(l, r, x));
            se.erase(from, to);
            for (S s : q) se.insert(s);
            q.clear();
        } else {
            scanf("%d%d", &l, &r), --l, --r;
            printf("%I64d\n", stGet(1, 0, off - 1, l, r));
        }
    }
    return 0;
}