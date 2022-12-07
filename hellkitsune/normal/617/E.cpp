#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Q {
    int from, to, ind;
};

int n, m, k;
int a[100001] = {};
LL ans[100000];
Q q[100000];
const int ROOT = 320;

inline bool cmp(const Q &lhs, const Q &rhs) {
    int l = lhs.from / ROOT, r = rhs.from / ROOT;
    if (l != r) return l < r;
    return lhs.to < rhs.to;
}

LL curAns = 0;
int state = 0;
int rev[111111], cnt[1 << 20];
LL revAns[111111];

void add(int x) {
    revAns[state] = curAns;
    curAns += cnt[x ^ k];
    ++cnt[x];
    rev[state++] = x;
}

void revertTo(int ind) {
    if (ind != state) curAns = revAns[ind];
    while (state > ind) {
        int x = rev[--state];
        --cnt[x];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%d", a + i + 1);
    REP(i, n) a[i + 1] ^= a[i];
    ++n;
    REP(i, m) scanf("%d%d", &q[i].from, &q[i].to), q[i].ind = i, --q[i].from;
    sort(q, q + m, cmp);
    int cur = 0, pos = ROOT;
    REP(z, m) {
        int from = q[z].from;
        int to = q[z].to;
        if (to / ROOT == from / ROOT) {
            continue;
        }
        if (cur != from / ROOT) {
            cur = from / ROOT;
            revertTo(0);
            pos = (cur + 1) * ROOT;
        }
        while (pos <= to) {
            add(a[pos++]);
        }
        int saveState = state;
        for (int i = (cur + 1) * ROOT - 1; i >= from; --i) {
            add(a[i]);
        }
        ans[q[z].ind] = curAns;
        revertTo(saveState);
    }
    REP(z, m) {
        int from = q[z].from;
        int to = q[z].to;
        if (to / ROOT != from / ROOT) {
            continue;
        }
        revertTo(0);
        for (int i = from; i <= to; ++i) {
            add(a[i]);
        }
        ans[q[z].ind] = curAns;
    }
    REP(i, m) printf("%I64d\n", ans[i]);
    return 0;
}