#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF64 = LL(1e18);

int n, k;
LL pre[3200][3200];
int a[100111];
int cnt[100000], ord[100000], inv[100000];
vector<int> w[100000];
int u[101000], *ub[100000], *ue[100000];
int c[420][100111];

inline bool cmp(const int &lhs, const int &rhs) {
    return cnt[lhs] > cnt[rhs];
}

LL getCost(int from, int to) {
    int f = (from + 15) >> 5;
    int t = (to + 15) >> 5;
    LL res = pre[f][t];
    f <<= 5;
    t <<= 5;
    while (t < to) {
        int num = a[t];
        if (num < 420) {
            res += c[num][t] - c[num][f];
        } else {
            res += lower_bound(ub[num], ue[num], t) - lower_bound(ub[num], ue[num], f);
        }
        ++t;
    }
    while (f > from) {
        int num = a[f - 1];
        if (num < 420) {
            res += c[num][t] - c[num][f];
        } else {
            res += lower_bound(ub[num], ue[num], t) - lower_bound(ub[num], ue[num], f);
        }
        --f;
    }
    while (t > to) {
        int num = a[t - 1];
        if (num < 420) {
            res -= c[num][t - 1] - c[num][f];
        } else {
            res -= lower_bound(ub[num], ue[num], t - 1) - lower_bound(ub[num], ue[num], f);
        }
        --t;
    }
    while (f < from) {
        int num = a[f];
        if (num < 420) {
            res -= c[num][t] - c[num][f + 1];
        } else {
            res -= lower_bound(ub[num], ue[num], t) - lower_bound(ub[num], ue[num], f + 1);
        }
        ++f;
    }
    return res;
}

LL d[100001], nd[100001];

void solve(int from, int to, int lo, int hi) {
    int mid = (from + to) >> 1;
    LL best = INF64;
    int bestInd = -1;
    LL cur = 0;
    for (int i = lo; i <= min(mid, hi); ++i) {
        cur += d[i];
        if (i == lo) {
            cur = d[i] + getCost(i, mid);
        } else {
            int num = a[i - 1];
            if (num < 420) {
                cur -= c[num][mid] - c[num][i];
            } else {
                cur -= lower_bound(ub[num], ue[num], mid) - lower_bound(ub[num], ue[num], i);
            }
        }
        if (cur < best) {
            best = cur;
            bestInd = i;
        }
        cur -= d[i];
    }
    nd[mid] = best;
    if (from < mid) solve(from, mid - 1, lo, bestInd);
    if (to > mid) solve(mid + 1, to, bestInd, hi);
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 100000;
        k = 20;
        forn(i, n) a[i] = mt() % 1500;
    } else {
        scanf("%d%d", &n, &k);
        forn(i, n) scanf("%d", a + i), --a[i];
    }

    int m = (n + 31) / 32;
    int nn = 32 * m;
    forn(i, nn) ++cnt[a[i]];
    forn(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    forn(i, n) inv[ord[i]] = i;
    forn(i, nn) a[i] = inv[a[i]];
    forn(i, 420) {
        forn(j, nn) c[i][j + 1] = c[i][j] + (a[j] == i);
    }

    forn(i, nn) w[a[i]].pb(i);
    int *it = u;
    forn(i, n) {
        ub[i] = ue[i] = it;
        for (int x : w[i]) {
            *it = x;
            ++it;
            ++ue[i];
        }
    }

    for (int i = 0; i < m; ++i) {
        memset(cnt, 0, sizeof cnt);
        LL res = 0;
        pre[i][i] = 0;
        for (int j = i * 32; j < nn; ++j) {
            res += cnt[a[j]]++;
            if (!((j + 1) & 31)) {
                pre[i][(j + 1) >> 5] = res;
            }
        }
    }

    forn(i, n + 1) d[i] = INF64;
    d[0] = 0;
    forn(i, k) {
        solve(0, n, 0, n);
        memcpy(d, nd, sizeof d);
    }
    cout << d[n] << endl;
    return 0;
}