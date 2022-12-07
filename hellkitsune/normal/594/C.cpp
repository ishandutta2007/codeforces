#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int x[100000], y[100000], xx[100000], yy[100000];
int ord[100000];
vector<int> inds;

inline bool cmpx(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

inline bool cmpy(const int &lhs, const int &rhs) {
    return y[lhs] < y[rhs];
}

vector<int> xs, ys;

void sortUnique(vector<int> &inds) {
    sort(inds.begin(), inds.end());
    inds.erase(unique(inds.begin(), inds.end()), inds.end());
}

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d%d%d%d", x + i, y + i, xx + i, yy + i), x[i] += xx[i], y[i] += yy[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmpx);
    REP(i, k + 1) inds.pb(ord[i]);
    REP(i, k + 1) inds.pb(ord[n - 1 - i]);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmpy);
    REP(i, k + 1) inds.pb(ord[i]);
    REP(i, k + 1) inds.pb(ord[n - 1 - i]);
    sortUnique(inds);
    for (int ind : inds) xs.pb(x[ind]), ys.pb(y[ind]);
    sortUnique(xs);
    sortUnique(ys);
    int xsz = (int)xs.size();
    int ysz = (int)ys.size();
    LL ans = 2e18;
    REP(i, xsz) for (int j = i; j < xsz; ++j) {
        int cnt = j - i + 1;
        if (xsz - cnt > k) continue;
        int xbeg = xs[i], xed = xs[j];
        REP(ii, ysz) for (int jj = ii; jj < ysz; ++jj) {
            cnt = jj - ii + 1;
            if (ysz - cnt > k) continue;
            int ybeg = ys[ii], yed = ys[jj];
            int bad = 0;
            for (int ind : inds) if (x[ind] < xbeg || x[ind] > xed || y[ind] < ybeg || y[ind] > yed) {
                ++bad;
            }
            if (bad <= k) {
                LL dx = ((LL)xed - xbeg + 1) / 2;
                LL dy = ((LL)yed - ybeg + 1) / 2;
                if (dx <= 0) dx = 1;
                if (dy <= 0) dy = 1;
                ans = min(ans, (LL)dx * dy);
            }
        }
    }
    cout << ans << endl;
    return 0;
}