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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int st[1 << 18];
const int off = 1 << 17;
int n;
int a[100000];
map<int, LL> ma;

void initSt() {
    REP(i, n) st[off + i] = a[i];
    for (int i = n; i < off; ++i) st[off + i] = 1;
    for (int i = off - 1; i >= 1; --i)
        st[i] = __gcd(st[i << 1], st[(i << 1) | 1]);
}

int searchSt(int v, int L, int R, int l, int g) {
    if (L == l) {
        if (st[v] % g == 0) return R;
        if (L == R) return L - 1;
        int mid = (L + R) >> 1;
        int ret = searchSt(v << 1, L, mid, l, g);
        if (ret == mid) ret = searchSt((v << 1) | 1, mid + 1, R, mid + 1, g);
        return ret;
    }
    int mid = (L + R) >> 1;
    if (l > mid) return searchSt((v << 1) | 1, mid + 1, R, l, g);
    int ret = searchSt(v << 1, L, mid, l, g);
    if (ret == mid) ret = searchSt((v << 1) | 1, mid + 1, R, mid + 1, g);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    initSt();
    REP(i, n) {
        int j = i;
        int curG = a[i];
        while (true) {
            int rj = (curG == 1) ? (n - 1) : searchSt(1, 0, off - 1, j, curG);
            ma[curG] += rj - j + 1;
            j = rj + 1;
            if (j == n) break;
            curG = __gcd(curG, a[j]);
        }
    }
    int m;
    cin >> m;
    REP(i, m) {
        int x;
        cin >> x;
        cout << ma[x] << '\n';
    }
    return 0;
}