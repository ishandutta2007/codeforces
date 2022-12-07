#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int p, whole, part;
    S(int p, int whole, int part) : p(p), whole(whole), part(part) {}
};

const int MOD = 1e9 + 7;
const int ROOT = 447;
int n, q;
int a[200000];
vector<S> p[200000];
int from[200000], to[200000];
bool bad[200000];
vector<int> ord;
bool pr[2000];
vector<int> all;
int was[1000000] = {};
int curAns = 1;
int *pos[1510000], sz = 0;
int ans[200000];

void backToState(int state) {
    while (sz > state) {
        *(pos[--sz]) = 0;
    }
}

inline bool cmp(const int &lhs, const int &rhs) {
    if (from[lhs] / ROOT != from[rhs] / ROOT) return from[lhs] < from[rhs];
    return to[lhs] < to[rhs];
}

void add(int i) {
    int mul = 1;
    for (S s : p[i]) {
        if (was[s.p]) {
            mul *= s.whole;
        } else {
            mul *= s.part;
            was[s.p] = 1;
            pos[sz++] = was + s.p;
        }
    }
    curAns = (LL)curAns * mul % MOD;
}

int main() {
    REP(i, 2000) pr[i] = true;
    pr[0] = pr[1] = false;
    REP(i, 2000) if (pr[i]) {
        for (int j = i * i; j < 2000; j += i) {
            pr[j] = false;
        }
    }
    REP(i, 2000) if (pr[i]) {
        all.pb(i);
    }
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    scanf("%d", &q);
    REP(i, q) scanf("%d%d", from + i, to + i), --from[i], --to[i];
    REP(i, q) {
        bad[i] = from[i] / ROOT == to[i] / ROOT;
        if (!bad[i]) ord.pb(i);
    }
    sort(ord.begin(), ord.end(), cmp);
    REP(i, n) {
        int x = a[i];
        for (int j = 0; all[j] * all[j] <= x; ++j) if (x % all[j] == 0) {
            int whole = all[j];
            int part = all[j] - 1;
            x /= all[j];
            while (x % all[j] == 0) {
                x /= all[j];
                whole *= all[j];
                part *= all[j];
            }
            p[i].pb(S(all[j], whole, part));
        }
        if (x > 1) p[i].pb(S(x, x, x - 1));
    }
    int nextL = ROOT;
    int r = ROOT - 1;
    for (int x : ord) {
        if (from[x] >= nextL) {
            backToState(0);
            curAns = 1;
            while (from[x] >= nextL) nextL += ROOT;
            r = nextL - 1;
        }
        while (r < to[x]) add(++r);
        int saveState = sz;
        int saveAns = curAns;
        for (int l = nextL - 1; l >= from[x]; --l) add(l);
        ans[x] = curAns;
        backToState(saveState);
        curAns = saveAns;
    }
    REP(x, q) if (bad[x]) {
        backToState(0);
        curAns = 1;
        for (int i = from[x]; i <= to[x]; ++i) {
            add(i);
        }
        ans[x] = curAns;
    }
    REP(i, q) printf("%d\n", ans[i]);
    return 0;
}