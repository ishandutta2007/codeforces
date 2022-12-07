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

int n, cnt, m;
map<int, int> ma;
int s[100000], re[100000], sc[100000];
vector<int> pos[100000];

int st[1 << 18];
const int off = 1 << 17;

void initSt() {
    REP(i, n) st[off + i] = s[i];
    for (int i = n; i < off; ++i) st[off + i] = 1;
    for (int i = off - 1; i >= 1; --i)
        st[i] = __gcd(st[i << 1], st[(i << 1) | 1]);
}

int querySt(int v, int L, int R, int l, int r) {
    if (l == L && r == R) return st[v];
    int mid = (L + R) >> 1;
    int ret1 = -1, ret2 = -1;
    if (l <= mid) ret1 = querySt(v << 1, L, mid, l, min(r, mid));
    if (r > mid) ret2 = querySt((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    if (ret1 == -1) return ret2;
    if (ret2 == -1) return ret1;
    return __gcd(ret1, ret2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> s[i], re[i] = s[i];
    sort(re, re + n);
    cnt = unique(re, re + n) - re;
    REP(i, cnt) ma[re[i]] = i;
    REP(i, n) sc[i] = ma[s[i]];
    REP(i, n) pos[sc[i]].pb(i);
    initSt();
    cin >> m;
    REP(i, m) {
        int l, r;
        cin >> l >> r, --l, --r;
        int g = querySt(1, 0, off - 1, l, r);
        auto it = ma.find(g);
        if (it == ma.end()) {
            cout << r - l + 1 << "\n";
            continue;
        }
        g = it->second;
        int sz = pos[g].size();
        vector<int> &cur = pos[g];
        int lo = 0, hi = sz, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (cur[mid] >= l)
                hi = mid;
            else
                lo = mid + 1;
        }
        int le = lo;
        lo = -1, hi = sz - 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (cur[mid] <= r)
                lo = mid;
            else
                hi = mid - 1;
        }
        int ri = lo;
        cout << r - l + 1 - max(0, ri - le + 1) << '\n';
    }
    return 0;
}