#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, k;
int a[35000], ri[35000], was[35000];
int d[35001], nd[35001];

vector<int> st[1 << 17];
const int off = 1 << 16;

void stBuild() {
    forn(i, n) for (int j = i + off; j >= 1; j >>= 1) {
        st[j].push_back(ri[i]);
    }
    forn(i, 2 * off) {
        sort(st[i].begin(), st[i].end());
    }
}

int gr;
inline int stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (l == L && r == R) {
        return lower_bound(st[v].begin(), st[v].end(), gr) - st[v].begin();
    }
    int mid = (L + R) >> 1;
    return stGet(2 * v, L, mid, l, min(r, mid)) +
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

void solve(int from, int to, int lo, int hi) {
    int mid = (from + to) >> 1;
    int nhi = min(hi, mid - 1);
    int bestRes = -1;
    int bestInd = -1;

    gr = mid;
    int delta = mid - lo - stGet(1, 0, off - 1, lo, mid - 1);

    for (int i = lo; i <= nhi; ++i) {
        if (i > lo) {
            delta -= ri[i - 1] >= mid;
        }
        int res = d[i] + delta;
        if (bestRes < res) {
            bestRes = res;
            bestInd = i;
        }
    }
    nd[mid] = bestRes;

    if (from < mid) solve(from, mid - 1, lo, bestInd);
    if (to > mid) solve(mid + 1, to, bestInd, hi);
}

int main() {
    if (0) {
        n = 35000;
        k = 50;
        mt19937 mt(123);
        forn(i, n) a[i] = mt() % n;
    } else {
        scanf("%d%d", &n, &k);
        forn(i, n) scanf("%d", a + i), --a[i];
    }
    forn(i, n) was[i] = n;
    for (int i = n - 1; i >= 0; --i) {
        ri[i] = was[a[i]];
        was[a[i]] = i;
    }
    stBuild();
    forn(i, n + 1) d[i] = -INF;
    d[0] = 0;
    forn(i, k) {
        forn(j, n + 1) nd[j] = -INF;
        solve(i + 1, n, 0, n);
        memcpy(d, nd, sizeof d);
    }
    cout << d[n] << endl;
    return 0;
}