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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, de;
LL _h[100000];
map<LL, int> ma;
set<LL> se;
int cnt = 0;
LL re[100000];
int h[100000];
PII st[1 << 18];
const int off = 1 << 17;
int d[100000], p[100000];
vector<int> ans;

void initSt() {
    REP(i, off << 1) st[i] = mp(0, -1);
}

void updateSt(int pos, PII val) {
    if (st[off + pos] < val) {
        for (pos += off; pos >= 1; pos >>= 1)
            st[pos] = max(st[pos], val);
    }
}

PII querySt(int v, int L, int R, int l, int r) {
    if (l > r) return mp(0, -1);
    if (l == L && r == R) return st[v];
    int mid = (L + R) >> 1;
    return max(querySt(v << 1, L, mid, l, min(r, mid)),
                querySt((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> de;
    REP(i, n) cin >> _h[i], se.insert(_h[i]);
    foreach(e, se) ma[*e] = cnt, re[cnt++] = *e;
    REP(i, n) h[i] = ma[_h[i]];
    se.clear();
    ma.clear();
    REP(i, n) d[i] = 1, p[i] = -1;
    initSt();
    updateSt(h[0], mp(1, 0));
    for (int i = 1; i < n; ++i) {
        LL cur = _h[i] - de;
        int lo = -1, hi = cnt - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (re[mid] <= cur)
                lo = mid;
            else
                hi = mid - 1;
        }
        if (lo != -1) {
            PII res = querySt(1, 0, off - 1, 0, lo);
            if (res.second != -1) {
                d[i] = res.first + 1;
                p[i] = res.second;
            }
        }
        cur = _h[i] + de;
        lo = 0, hi = cnt;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (re[mid] >= cur)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (hi != cnt) {
            PII res = querySt(1, 0, off - 1, hi, cnt - 1);
            if (res.second != -1 && res.first + 1 > d[i]) {
                d[i] = res.first + 1;
                p[i] = res.second;
            }
        }
        updateSt(h[i], mp(d[i], i));
    }
    int mx = 0;
    for (int i = 1; i < n; ++i) if (d[i] > d[mx])
        mx = i;
    cout << d[mx] << '\n';
    int cur = mx;
    REP(i, d[mx]) {
        ans.pb(cur);
        cur = p[cur];
    }
    for (int i = d[mx] - 1; i >= 0; --i)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}