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
typedef pair<LL, LL> PLL;

int n, m;
LL l[200000], r[200000];
LL a[200000];
vector<PLL> v;
int ord[200000], bord[200000];
int ans[200000] = {};

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (v[lhs].second != v[rhs].second) return v[lhs].second < v[rhs].second;
        return lhs < rhs;
    }
};

set<int, Cmp> se;

bool cmp(const int &lhs, const int &rhs) {
    return v[lhs].first < v[rhs].first;
}

bool bcmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> l[i] >> r[i];
    REP(i, m) cin >> a[i];
    REP(i, m) bord[i] = i;
    sort(bord, bord + m, bcmp);
    REP(i, n - 1) v.pb(mp(l[i + 1] - r[i], r[i + 1] - l[i]));
    --n;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    int pos = 0;
    REP(i, m) {
        while (pos < n && v[ord[pos]].first <= a[bord[i]]) {
            se.insert(ord[pos]);
            ++pos;
        }
        if (!se.empty()) {
            int cur = *se.begin();
            se.erase(se.begin());
            if (v[cur].second < a[bord[i]]) {
                printf("No\n");
                return 0;
            }
            ans[cur] = bord[i] + 1;
        }
    }
    REP(i, n) if (ans[i] == 0) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}