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

struct P {
    int x, y;
};

inline bool cmp(const P &lhs, const P &rhs) {
    return lhs.x < rhs.x;
}

inline bool cmp2(const P &lhs, const P &rhs) {
    return lhs.y < rhs.y;
}

inline LL dist(const P &a, const P &b) {
    return (a.x - b.x) * LL(a.x - b.x) + (a.y - b.y) * LL(a.y - b.y);
}

int n;
P p[100000], t[100000];
LL ans = (LL)4e18;

void solve(int from, int to) {
    if (to - from < 5) {
        for (int i = from; i < to - 1; ++i) {
            for (int j = i + 1; j < to; ++j) {
                ans = min(ans, dist(p[i], p[j]));
            }
        }
        sort(p + from, p + to, cmp2);
        return;
    }
    int mid = (from + to + 1) >> 1;
    int midX = p[mid].x;
    solve(from, mid);
    solve(mid, to);
    merge(p + from, p + mid, p + mid, p + to, t, cmp2);
    copy(t, t + (to - from), p + from);
    int sz = 0;
    for (int i = from; i < to; ++i) {
        if ((p[i].x - midX) * (p[i].x - midX) < ans) {
            for (int j = sz - 1; j >= 0 && (p[i].y - t[j].y) * (p[i].y - t[j].y) < ans; --j) {
                ans = min(ans, dist(p[i], t[j]));
            }
            t[sz++] = p[i];
        }
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) p[i].x = i;
    REP(i, n) scanf("%d", &p[i].y);
    for (int i = 1; i < n; ++i) p[i].y += p[i - 1].y;
    sort(p, p + n, cmp);
    solve(0, n);
    cout << ans << endl;
    return 0;
}