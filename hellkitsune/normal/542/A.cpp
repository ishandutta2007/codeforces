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

int n, m;
int l[200000], r[200000];
int a[200000], b[200000], c[200000];
int d[800000], p[800000];
set<int> se;
map<int, int> ma;
int rev[800000];
int mac = 0;
LL ans = 0;
int ansi, ansj;
PII fen[800000];

void fenUpdate(int pos, PII val) {
    for (; pos < mac; pos |= pos + 1)
        fen[pos] = max(fen[pos], val);
}

PII fenGet(int pos) {
    PII ret = mp(-1, -1);
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret = max(ret, fen[pos]);
    return ret;
}

struct Ev {
    int x;
    bool i;
    int ind;
    Ev(int x, bool i, int ind) : x(x), i(i), ind(ind) {}
    Ev() {}
};

Ev e[400000];
int ec = 0;

bool cmp(const Ev &lhs, const Ev &rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.i < rhs.i;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d%d", l + i, r + i);
    REP(i, m) scanf("%d%d%d", a + i, b + i, c + i);
    REP(i, n) se.insert(l[i]), se.insert(r[i]);
    REP(i, m) se.insert(a[i]), se.insert(b[i]);
    for (int x : se) ma[x] = mac, rev[mac++] = x;
    REP(i, n) l[i] = ma[l[i]], r[i] = ma[r[i]];
    REP(i, m) a[i] = ma[a[i]], b[i] = ma[b[i]];
    REP(i, mac) d[i] = -1;
    REP(i, n) if (r[i] > d[l[i]]) {
        d[l[i]] = r[i];
        p[l[i]] = i;
    }
    for (int i = 1; i < mac; ++i) if (d[i - 1] > d[i]) {
        d[i] = d[i - 1];
        p[i] = p[i - 1];
    }
    REP(i, m) if (d[a[i]] > a[i]) {
        int r = min(b[i], d[a[i]]);
        LL cur = (rev[r] - rev[a[i]]) * (LL)c[i];
        if (cur > ans) {
            ans = cur;
            ansi = p[a[i]];
            ansj = i;
        }
    }
    REP(i, mac) d[i] = mac;
    REP(i, n) if (l[i] < d[r[i]]) {
        d[r[i]] = l[i];
        p[r[i]] = i;
    }
    for (int i = mac - 2; i >= 0; --i) if (d[i + 1] < d[i]) {
        d[i] = d[i + 1];
        p[i] = p[i + 1];
    }
    REP(i, m) if (d[b[i]] < b[i]) {
        int l = max(a[i], d[b[i]]);
        LL cur = (rev[b[i]] - rev[l]) * (LL)c[i];
        if (cur > ans) {
            ans = cur;
            ansi = p[b[i]];
            ansj = i;
        }
    }
    REP(i, mac) fen[i] = mp(-1, -1);
    REP(i, n) e[ec++] = Ev(l[i], true, i);
    REP(i, m) e[ec++] = Ev(a[i], false, i);
    sort(e, e + ec, cmp);
    for (Ev ev : e) {
        if (ev.i) {
            PII ret = fenGet(mac - 1 - r[ev.ind]);
            if (ret.first != -1) {
                LL cur = (LL)ret.first * (rev[r[ev.ind]] - rev[l[ev.ind]]);
                if (cur > ans) {
                    ans = cur;
                    ansi = ev.ind;
                    ansj = ret.second;
                }
            }
        } else {
            fenUpdate(mac - 1 - b[ev.ind], mp(c[ev.ind], ev.ind));
        }
    }
    cout << ans << endl;
    if (ans != 0) cout << ansi + 1 << ' ' << ansj + 1 << endl;
    return 0;
}