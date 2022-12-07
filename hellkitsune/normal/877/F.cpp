#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, q;
LL bal[100001];
int b[100001];
int nx[100001], pre[100001];
LL all[100001];
int allc;
int from[100001], to[100001];

int ord[100001];

const int S = 316;
inline bool cmp(const int &lhs, const int &rhs) {
    int lblock = from[lhs] / S;
    int rblock = from[rhs] / S;
    if (lblock != rblock) {
        return lblock < rblock;
    }
    return lblock & 1 ? to[lhs] < to[rhs] : to[rhs] < to[lhs];
}

LL ans = 0;
int cnt[100001];
int l = 0, r = -1;

inline void lmm() {
    --l;
    if (nx[b[l]] != -1) {
        ans += cnt[nx[b[l]]];
    }
    ++cnt[b[l]];
}

inline void lpp() {
    --cnt[b[l]];
    if (nx[b[l]] != -1) {
        ans -= cnt[nx[b[l]]];
    }
    ++l;
}

inline void rpp() {
    ++r;
    if (pre[b[r]] != -1) {
        ans += cnt[pre[b[r]]];
    }
    ++cnt[b[r]];
}

inline void rmm() {
    --cnt[b[r]];
    if (pre[b[r]] != -1) {
        ans -= cnt[pre[b[r]]];
    }
    --r;
}

LL res[100001];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            bal[i + 1] = 1;
        } else {
            bal[i + 1] = -1;
        }
    }
    forn(i, n) {
        int x;
        scanf("%d", &x);
        bal[i + 1] = bal[i] + bal[i + 1] * x;
    }
    ++n;
//    forn(i, n) cerr << bal[i] << ' ';
//    cerr << endl;
    scanf("%d", &q);
    forn(i, q) {
        scanf("%d%d", from + i, to + i);
        --from[i];
    }
    forn(i, n) all[i] = bal[i];
    sort(all, all + n);
    allc = unique(all, all + n) - all;
    forn(i, n) b[i] = lower_bound(all, all + allc, bal[i]) - all;
    int iter = 0;
    memset(nx, -1, sizeof nx);
    memset(pre, -1, sizeof pre);
    forn(i, allc) {
        while (iter < allc && all[iter] < all[i] + k) {
            ++iter;
        }
        if (iter != allc && all[iter] == all[i] + k) {
            nx[i] = iter;
            pre[iter] = i;
        }
    }
//    forn(i, n) cerr << b[i] << ' ';
//    cerr << endl;
//    forn(i, allc) cerr << nx[i] << ' ';
//    cerr << endl;
//    forn(i, allc) cerr << pre[i] << ' ';
//    cerr << endl;
    forn(i, q) ord[i] = i;
    sort(ord, ord + q, cmp);
    forn(ii, q) {
        int i = ord[ii];
        while (r < to[i]) {
            rpp();
        }
        while (l > from[i]) {
            lmm();
        }
        while (r > to[i]) {
            rmm();
        }
        while (l < from[i]) {
            lpp();
        }
        res[i] = ans;
    }
    forn(i, q) printf("%I64d\n", res[i]);
    return 0;
}