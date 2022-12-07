#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100005];
LL d[100005];
int prevMax[100005];
PII st[1 << 18] = {};
const int off = 1 << 17;

void stBuild() {
    REP(i, n - 1) st[off + i] = mp(a[i], i);
    for (int i = off - 1; i >= 1; --i) {
        st[i] = max(st[2 * i], st[2 * i + 1]);
    }
}

PII stGet(int v, int L, int R, int l, int r) {
    if (l > r) return mp(-1, -1);
    if (l == L && r == R) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    return max(stGet(2 * v, L, mid, l, min(r, mid)),
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r));
}

int ii;

LL solve(int from, int pos) {
    if (pos == n - 1) return 0;
    if (prevMax[pos] >= ii) return d[pos];
    PII mx = stGet(1, 0, off - 1, from, pos);
    prevMax[pos] = mx.second;
    return d[pos] = solve(pos + 1, mx.first) + n - 1 - pos;
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) scanf("%d", a + i), --a[i];
    stBuild();
    memset(prevMax, -1, sizeof prevMax);
    LL ans = 0;
    for (ii = 0; ii < n - 1; ++ii) {
        ans += solve(ii, ii);
    }
    cout << ans << endl;
    return 0;
}