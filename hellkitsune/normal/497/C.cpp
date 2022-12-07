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
    int a, ind;
    bool act, fn;
    Ev(int a, int ind, bool act, bool fn) : a(a), ind(ind), act(act), fn(fn) {}
    Ev() {}
};

int n, m;
int a[100000], b[100000], c[100000], d[100001], k[100000];
Ev e[300000];
int ec = 0;

bool cmp(const Ev &lhs, const Ev &rhs) {
    if (lhs.a == rhs.a) {
        return lhs.act && !rhs.act;
    }
    return lhs.a < rhs.a;
}

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (d[lhs] == d[rhs]) return lhs > rhs;
        return d[lhs] < d[rhs];
    }
};

set<int, Cmp> se;
int ans[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i] >> b[i];
    cin >> m;
    REP(i, m) cin >> c[i] >> d[i] >> k[i];
    REP(i, n) e[ec++] = Ev(a[i], i, false, false);
    REP(i, m) e[ec++] = Ev(c[i], i, true, false);
    REP(i, m) e[ec++] = Ev(d[i] + 1, i, true, true);
    sort(e, e + ec, cmp);
    REP(i, ec) {
        if (e[i].act) {
            if (e[i].fn) {
                se.erase(e[i].ind);
            } else {
                se.insert(e[i].ind);
            }
        } else {
            d[m] = b[e[i].ind];
            auto it = se.lower_bound(m);
            if (it == se.end()) {
                cout << "NO\n";
                return 0;
            }
            int ind = *it;
            ans[e[i].ind] = ind + 1;
            if (--k[ind] == 0) {
                se.erase(ind);
            }
        }
    }
    cout << "YES\n";
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}