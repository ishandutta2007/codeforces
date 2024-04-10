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
    int p, e;
    P(int p, int e) : p(p), e(e) {}
    P() {}
};

int n, k;
P a[200000];

bool cmp(const P &lhs, const P &rhs) {
    if (lhs.p != rhs.p)
        return lhs.p > rhs.p;
    return lhs.e < rhs.e;
}

bool used[200000];
vector<int> q;

bool cmp2(const int &lhs, const int &rhs) {
    return a[lhs].e < a[rhs].e;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k, --k;
    REP(i, n) cin >> a[i].p >> a[i].e;
    sort(a, a + n, cmp);
    int targ = a[k].p;
    if (targ > n) {
        cout << -1 << endl;
        return 0;
    }
    LL ans = 1e18;
    for (int pp = targ; pp <= min(targ + 2, n); ++pp) {
        int l = -1, r = -1, place = 0;
        REP(i, n) {
            if (a[i].p + 1 >= pp) {
                ++place;
                if (a[i].p <= pp) {
                    r = i;
                    if (l == -1)
                        l = i;
                }
            }
        }
        REP(i, n) used[i] = false;
        LL cur = 0;
        int curP = 0;
        if (place > k) {
            if (l == -1 || r - l + 1 < place - k) {
                continue;
            }
            for (int i = l; i <= r; ++i)
                q.pb(i);
            sort(q.begin(), q.end(), cmp2);
            REP(i, place - k) {
                cur += a[q[i]].e;
                ++curP;
                used[q[i]] = true;
            }
            q.clear();
        }
        if (curP > pp) continue;
        REP(i, n) if (!used[i])
            q.pb(i);
        sort(q.begin(), q.end(), cmp2);
        REP(i, pp - curP)
            cur += a[q[i]].e;
        q.clear();
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}