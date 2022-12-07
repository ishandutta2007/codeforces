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
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    LL ind;
    bool st;
    S(LL ind, bool st) : ind(ind), st(st) {}
    S() {}
};

int h, q;
int i, qans;
LL l, r;
LL from, to;
vector<S> s;
LL ans = -1;

bool cmp(const S &lhs, const S &rhs) {
    return lhs.ind < rhs.ind;
}

int main() {
    scanf("%d%d", &h, &q);
    from = 0, to = 1ll << (h - 1);
    REP(z, q) {
        scanf("%d%I64d%I64d%d", &i, &l, &r, &qans);
        LL mul = 1ll << (h - i);
        LL beg = 1ll << (i - 1);
        l -= beg;
        r -= beg;
        if (qans == 1) {
            from = max(from, l * mul);
            to = min(to, (r + 1) * mul);
        } else {
            s.pb(S(l * mul, true));
            s.pb(S((r + 1) * mul, false));
        }
    }
    s.pb(S((LL)1e18, true));
    sort(s.begin(), s.end(), cmp);
    //for (S ev : s) cout << ev.ind << ' ' << ev.st << endl;
    LL pre = 0;
    int bal = 0;
    for (S ev : s) {
        if (bal == 0 && ans != -2) {
            LL curFrom = max(from, pre);
            LL curTo = min(to, ev.ind);
            if (curTo > curFrom + 1) {
                ans = -2;
            } else if (curTo == curFrom + 1) {
                if (ans != -1) {
                    ans = -2;
                } else {
                    ans = curFrom;
                }
            }
        }
        if (ev.st) ++bal;
        else --bal;
        pre = ev.ind;
    }
    if (ans >= 0) ans += 1ll << (h - 1);
    if (ans >= 0) cout << ans << endl;
    else if (ans == -2) cout << "Data not sufficient!" << endl;
    else cout << "Game cheated!" << endl;
    return 0;
}