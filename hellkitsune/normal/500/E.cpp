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

int n, q;
int x[200000], l[200000];
int d[20][200000], e[20][200000], f[20][200000];
PII st[1 << 19];
const int off = 1 << 18;

void initSt() {
    REP(i, off << 1) st[i] = mp(-1, -1);
}

void stUpdate(int pos, PII val) {
    st[off + pos] = max(st[off + pos], val);
    for (pos = (off + pos) >> 1; pos >= 1; pos >>= 1)
        st[pos] = max(st[pos << 1], st[(pos << 1) | 1]);
}

PII stGet(int v, int L, int R, int l, int r) {
    if (l > r) return mp(-1, -1);
    if (L == l && R == r) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    return max(stGet(v << 1, L, mid, l, min(r, mid)),
               stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> x[i] >> l[i];
    REP(i, n) d[0][i] = 0;
    initSt();
    for (int i = n - 1; i >= 0; --i) {
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (x[i] + l[i] < x[mid])
                hi = mid - 1;
            else
                lo = mid;
        }
        if (lo == i) e[0][i] = i, f[0][i] = x[i] + l[i];
        else {
            PII res = stGet(1, 0, off - 1, i + 1, lo);
            e[0][i] = res.first;
            f[0][i] = max(res.second, x[i] + l[i]);
        }
        stUpdate(i, mp(e[0][i], f[0][i]));
    }
    for (int i = 1; (1 << i) <= n; ++i) for (int j = 0; j + (1 << i) - 1 < n; ++j) {
        int pos = j, res = 0, t = j + (1 << i) - 1;
        int k = i - 1;
        while (pos < t) {
            int opos = pos;
            while (pos + (1 << k) > t) --k;
            res += d[k][pos];
            e[i][j] = e[k][pos];
            f[i][j] = f[k][pos];
            pos = e[k][pos];
            if (pos >= t) break;
            res += x[pos + 1] - f[k][opos];
            e[i][j] = e[0][pos + 1];
            f[i][j] = f[0][pos + 1];
            ++pos;
        }
        d[i][j] = res;
    }
    cin >> q;
    REP(query, q) {
        int from, to;
        cin >> from >> to, --from, --to;
        int pos = from, res = 0, t = to;
        int k = 18;
        while (pos < t) {
            int opos = pos;
            while (pos + (1 << k) > t) --k;
            res += d[k][pos];
            pos = e[k][pos];
            if (pos >= t) break;
            res += x[pos + 1] - f[k][opos];
            ++pos;
        }
        cout << res << '\n';
    }
    return 0;
}