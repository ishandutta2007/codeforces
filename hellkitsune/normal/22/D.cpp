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
    int x, ind;
    bool st;
    P(int x = 0, int ind = 0, bool st = false) : x(x), ind(ind), st(st) {}
};

int n;
int a[1000], b[1000];
vector<int> ans;
P p[2000];
bool used[1000] = {};

bool cmp(const P &lhs, const P &rhs) {
    if (lhs.x == rhs.x) {
        return lhs.st;
    }
    return lhs.x < rhs.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) if (b[i] < a[i]) swap(a[i], b[i]);
    REP(i, n) p[i] = P(a[i], i, true);
    REP(i, n) p[n + i] = P(b[i], i, false);
    sort(p, p + n + n, cmp);
    REP(i, 2 * n) if (p[i].st) {
        used[p[i].ind] = true;
    } else if (used[p[i].ind]) {
        REP(j, n) used[j] = false;
        ans.pb(p[i].x);
    }
    cout << (int)ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}