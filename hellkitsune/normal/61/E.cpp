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

int n;
int a[1000000], ord[1000000];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int fen[1000000];

void fenInc(int pos) {
    for (; pos < n; pos |= pos + 1)
        ++fen[pos];
}

int fenGet(int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

int f[1000000], g[1000000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) a[i] = ord[i];
    REP(i, n) {
        f[i] = fenGet(n - 1 - a[i]);
        fenInc(n - 1 - a[i]);
    }
    REP(i, n) fen[i] = 0;
    for (int i = n - 1; i >= 0; --i) {
        g[i] = fenGet(a[i]);
        fenInc(a[i]);
    }
    LL ans = 0;
    REP(i, n) ans += (LL)f[i] * g[i];
    cout << ans << endl;
    return 0;
}