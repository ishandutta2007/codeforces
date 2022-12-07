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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[500000], cnt = 0, re[500000], fi[500000], la[500000];
int z[500000][4];
set<int> se;
map<int, int> ma;
vector<int> ans;
int pos = 0;
PII st[1 << 20];
const int off = 1 << 19;

void stInit() {
    REP(i, off) st[off + i] = mp(-1, i);
    for (int i = off - 1; i >= 1; --i)
        st[i] = max(st[i << 1], st[(i << 1) | 1]);
}

void stUpdate(int pos, int val) {
    st[pos + off].first = val;
    for (pos = (pos + off) >> 1; pos >= 1; pos >>= 1)
        st[pos] = max(st[pos << 1], st[(pos << 1) | 1]);
}

PII stGet(int v, int L, int R, int l, int r) {
    if (l > r) return mp(-1, -1);
    if (l == L && r == R) return st[v];
    int mid = (L + R) >> 1;
    return max(stGet(v << 1, L, mid, l, min(r, mid)),
                stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), se.insert(a[i]);
    foreach(e, se) re[cnt] = *e, ma[*e] = cnt++;
    REP(i, n) a[i] = ma[a[i]];
    se.clear(), ma.clear();
    REP(i, cnt) fi[i] = -1, la[i] = -1;
    REP(i, cnt) REP(j, 4) z[i][j] = -1;
    stInit();
    REP(i, n) {
        REP(j, 3) z[a[i]][j] = z[a[i]][j + 1];
        z[a[i]][3] = i;
        if (z[a[i]][0] >= pos) {
            ans.pb(a[i]);
            ans.pb(a[i]);
            ans.pb(a[i]);
            ans.pb(a[i]);
            for (int j = pos; j <= i; ++j)
                stUpdate(j, -1);
            pos = i + 1;
            continue;
        }
        if (la[a[i]] < pos) {
            la[a[i]] = fi[a[i]] = i;
        } else {
            PII res = stGet(1, 0, off - 1, 0, la[a[i]] - 1);
            if (res.first > la[a[i]]) {
                ans.pb(a[res.second]);
                ans.pb(a[i]);
                ans.pb(a[res.second]);
                ans.pb(a[i]);
                for (int j = pos; j <= i; ++j)
                    stUpdate(j, -1);
                pos = i + 1;
            } else
                stUpdate(fi[a[i]], i);
            la[a[i]] = i;
        }
    }
    printf("%d\n", (int)ans.size());
    REP(i, ans.size())
        printf("%d ", re[ans[i]]);
    printf("\n");
    return 0;
}