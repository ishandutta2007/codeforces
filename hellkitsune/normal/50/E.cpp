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
    int ind;
    bool st;
    S(int ind, bool st) : ind(ind), st(st) {}
};

int n, m;
LL ans = 0;
vector<S> s;

inline bool cmp(const S &lhs, const S &rhs) {
    return lhs.ind < rhs.ind;
}

int main() {
    cin >> n >> m;
    for (int b = 1; b <= n; ++b) {
        int lo = 0, hi = b, mid;
        LL b2 = (LL)b * b;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (b2 - (LL)mid * mid > m)
                lo = mid + 1;
            else
                hi = mid;
        }
        ans += 2 * min(b2, (LL)m) - (m >= b2) - 2 * (b - lo) + (lo == 0);
        if (lo < b) {
            int from = lo;
            int to = b - 1;
            s.pb(S(-b - to, true));
            s.pb(S(-b - from + 1, false));
            s.pb(S(-b + from, true));
            s.pb(S(-b + to + 1, false));
        }
    }
    s.pb(S((int)1e9, true));
    sort(s.begin(), s.end(), cmp);
    int pre = -1e9;
    int bal = 0;
    for (S x : s) {
        if (bal > 0) {
            ans += x.ind - pre;
        }
        if (x.st) ++bal;
        else --bal;
        pre = x.ind;
    }
    cout << ans << endl;
    return 0;
}