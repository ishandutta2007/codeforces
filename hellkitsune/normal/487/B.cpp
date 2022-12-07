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

int n, s, l;
int a[100005];
int stmin[17][100005], stmax[17][100005];
int rev[100005];
int rm[100005];
int st[1 << 18];
const int off = 1 << 17;
int mx = 0;
const int INF = 1e9;

void initSt() {
    REP(i, off << 1) st[i] = INF;
    st[off] = 0;
}

int updVal = -1;
void updateSt(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        st[v] = min(st[v], updVal);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) updateSt(v << 1, L, mid, l, min(r, mid));
    if (r > mid) updateSt((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int querySt(int pos) {
    int ret = INF;
    for (pos += off; pos >= 1; pos >>= 1)
        ret = min(ret, st[pos]);
    return ret;
}

void init() {
    while ((1 << (mx + 1)) <= n) ++mx;
    int cur = 0, nx = 2;
    REP(i, n + 1) {
        if (i & nx) {
            ++cur;
            nx <<= 1;
        }
        rev[i] = cur;
    }
}

inline int getMin(int l, int r) {
    int ind = rev[r - l + 1];
    return min(stmin[ind][l], stmin[ind][r - (1 << ind) + 1]);
}

inline int getMax(int l, int r) {
    int ind = rev[r - l + 1];
    return max(stmax[ind][l], stmax[ind][r - (1 << ind) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> l;
    REP(i, n) cin >> a[i];
    init();
    REP(i, n) stmin[0][i] = stmax[0][i] = a[i];
    for (int i = 1; i <= mx; ++i) {
        int upTo = n - (1 << (i - 1));
        REP(j, upTo) stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][j + (1 << (i - 1))]);
        REP(j, upTo) stmax[i][j] = max(stmax[i - 1][j], stmax[i - 1][j + (1 << (i - 1))]);
    }
    rm[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        int lo = i, hi = rm[i + 1], mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (getMin(i, mid) < a[i] - s || getMax(i, mid) > a[i] + s)
                hi = mid - 1;
            else
                lo = mid;
        }
        rm[i] = lo;
    }
    initSt();
    REP(i, n) {
        int cur = querySt(i);
        if (cur != INF && rm[i] - i + 1 >= l) {
            updVal = cur + 1;
            updateSt(1, 0, off - 1, i + l, rm[i] + 1);
        }
    }
    int ans = querySt(n);
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}