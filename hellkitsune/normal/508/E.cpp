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

int n;
int a[600], b[600];
int d[600][600] = {};
int p[600][600], t[600][600];

int go(int from, int to) {
    if (from > to) return 1;
    if (d[from][to] != -1) return d[from][to];
    for (int nto = from; nto < to; ++nto) {
        if (go(from, nto) && go(nto + 1, to)) {
            t[from][to] = 1;
            p[from][to] = nto;
            return d[from][to] = 1;
        }
    }
    int val = (to - from) * 2 + 1;
    if (a[from] <= val && val <= b[from] && go(from + 1, to)) {
        t[from][to] = 2;
        return d[from][to] = 1;
    }
    return d[from][to] = 0;
}

string ans(int from, int to) {
    if (from > to) return "";
    if (t[from][to] == 2) return "(" + ans(from + 1, to) + ")";
    return ans(from, p[from][to]) + ans(p[from][to] + 1, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) REP(j, n) d[i][j] = -1;
    if (!go(0, n - 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans(0, n - 1) << endl;
    return 0;
}