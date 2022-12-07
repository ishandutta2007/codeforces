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

struct E {
    int pos, ind, val;
    E(int pos, int ind, int val) : pos(pos), ind(ind), val(val) {}
};

int n;
int h[100000], l[100000], r[100000];
vector<E> ev;

inline bool cmp(const E &lhs, const E &rhs) {
    return lhs.pos < rhs.pos;
}

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) {
        if (h[lhs] != h[rhs]) return h[lhs] > h[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> se;
vector<PII> ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n) scanf("%d%d%d", h + i, l + i, r + i);
    REP(i, n) ev.pb(E(l[i], i, +1));
    REP(i, n) ev.pb(E(r[i], i, -1));
    sort(ev.begin(), ev.end(), cmp);
    int sz = (int)ev.size();
    for (int beg = 0; beg < sz; ) {
        int end = beg + 1;
        while (end < sz && ev[beg].pos == ev[end].pos) ++end;
        for (int i = beg; i < end; ++i) {
            if (ev[i].val == 1) {
                se.insert(ev[i].ind);
            } else {
                se.erase(ev[i].ind);
            }
        }
        int curh = 0;
        if (!se.empty()) {
            curh = h[*se.begin()];
        }
        int x = ev[beg].pos;
        if (ans.empty()) {
            ans.pb(mp(x, 0));
            ans.pb(mp(x, curh));
        } else {
            int asz = (int)ans.size();
            if (asz == 1 || ans[asz - 1].second != ans[asz - 2].second) {
                ans.pb(mp(x, ans[asz - 1].second));
            } else {
                ans[asz - 1].first = x;
            }
            if (ans[asz - 1].second != curh) {
                ans.pb(mp(x, curh));
            }
        }
        beg = end;
    }
    printf("%d\n", (int)ans.size());
    for (PII x : ans) printf("%d %d\n", x.first, x.second);
    return 0;
}