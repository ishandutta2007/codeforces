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
    int pos, qi;
    bool st;
    E(int pos, int qi, bool st) : pos(pos), qi(qi), st(st) {}
    E() {}
};

int n, m, M;
int l[100000], r[100000], q[100000];
E e[200000];
int ans[100005] = {};

bool cmp(const E &lhs, const E &rhs) {
    return lhs.pos < rhs.pos;
}

int st[1 << 18] = {};
const int off = 1 << 17;

void updateSt(int pos, bool use) {
    if (use) st[off + pos] = q[pos];
    else st[off + pos] = 0;
    for (pos = ((off + pos) >> 1); pos >= 1; pos >>= 1)
        st[pos] = st[pos << 1] | st[(pos << 1) | 1];
}

inline int querySt() {
    return st[1];
}

int sta[1 << 18] = {};
const int MASK = (1 << 30) - 1;

void initSta() {
    REP(i, n) sta[off + i] = ans[i];
    for (int i = off - 1; i >= 1; --i)
        sta[i] = sta[i << 1] & sta[(i << 1) | 1];
}

int querySta(int v, int L, int R, int l, int r) {
    if (l > r) return MASK;
    if (l == L && r == R) return sta[v];
    int mid = (L + R) >> 1;
    return querySta(v << 1, L, mid, l, min(r, mid)) &
            querySta((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        cin >> l[i] >> r[i] >> q[i], --l[i], --r[i];
        e[i << 1] = E(l[i], i, true);
        e[(i << 1) | 1] = E(r[i] + 1, i, false);
    }
    M = m << 1;
    sort(e, e + M, cmp);
    int lst = 0, val = 0;
    for (int i = 0; i < M; ) {
        int j = i;
        while (j < M && e[j].pos == e[i].pos) ++j;
        for (int k = i; k < j; ++k)
            updateSt(e[k].qi, e[k].st);
        int res = querySt();
        for (int k = lst; k < e[i].pos; ++k)
            ans[k] = val;
        val = res;
        lst = e[i].pos;
        i = j;
    }
    assert(val == 0);
    initSta();
    REP(i, m) if (querySta(1, 0, off - 1, l[i], r[i]) != q[i]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}