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

struct Ev {
    int y;
    bool ver;
    int ind;
    Ev(int y, bool ver, int ind) : y(y), ver(ver), ind(ind) {}
    Ev() {}
};

int n, m;
int x[50000], y[50000], l[50000];
int xx[50000], yy[50000], ll[50000];
set<int> se;
Ev ev[222222];
int evc;

bool cmp(const Ev &lhs, const Ev &rhs) {
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    if (lhs.ver) return !rhs.ver;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> x[i] >> y[i] >> l[i];
    REP(i, m) cin >> xx[i] >> yy[i] >> ll[i];
    int lo = 0, hi = 1e8 + 1, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        evc = 0;
        REP(i, n) if (l[i] >= (mid << 1)) {
            ev[evc++] = Ev(y[i] + mid, true, i);
            ev[evc++] = Ev(y[i] + l[i] + 1 - mid, true, i);
        }
        REP(i, m) if (ll[i] >= (mid << 1)) {
            ev[evc++] = Ev(yy[i], false, i);
        }
        sort(ev, ev + evc, cmp);
        bool flag = false;
        REP(i, evc) {
            if (ev[i].ver) {
                if (ev[i].y == y[ev[i].ind] + mid)
                    se.insert(x[ev[i].ind]);
                else
                    se.erase(x[ev[i].ind]);
            } else {
                int from = xx[ev[i].ind] + mid;
                int to = xx[ev[i].ind] + ll[ev[i].ind] - mid;
                auto it = se.lower_bound(from);
                if (it != se.end() && *it <= to) {
                    flag = true;
                    break;
                }
            }
        }
        se.clear();
        if (flag) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}