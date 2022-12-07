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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

struct E {
    int u, v, w;
};

int n, m;
int d[300000];
E e[300000];
int a[300000], b[300000];

bool cmp(const E &lhs, const E &rhs) {
    return lhs.w < rhs.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) cin >> e[i].u >> e[i].v >> e[i].w, --e[i].u, --e[i].v;
    sort(e, e + m, cmp);
    REP(i, n) d[i] = 0;
    for (int i = 0; i < m; ) {
        int j = i + 1;
        while (j < m && e[j].w == e[i].w) ++j;
        for (int k = i; k < j; ++k) {
            a[k] = e[k].v;
            b[k] = d[e[k].u] + 1;
        }
        for (int k = i; k < j; ++k)
            d[a[k]] = max(d[a[k]], b[k]);
        i = j;
    }
    int ans = 0;
    REP(i, n) ans = max(ans, d[i]);
    cout << ans << '\n';
    return 0;
}