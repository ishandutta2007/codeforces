#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e7);

int n;
int x[200005], y[200005];
int a[200005], b[200005], cnt;
int all[200005], bll[200005], ac, bc;
PII p[200005];
int lo[200005], hi[200005];

void nor(int *a) {
    int mn = a[0];
    forn(i, cnt) mn = min(mn, a[i]);
    forn(i, cnt) a[i] -= mn;
}

LL solve() {
    nor(a);
    nor(b);
    forn(i, cnt) all[i] = a[i];
    forn(i, cnt) bll[i] = b[i];
    sort(all, all + cnt);
    ac = unique(all, all + cnt) - all;
    sort(bll, bll + cnt);
    bc = unique(bll, bll + cnt) - bll;
    forn(i, cnt) a[i] = lower_bound(all, all + ac, a[i]) - all;
    forn(i, cnt) b[i] = lower_bound(bll, bll + bc, b[i]) - bll;
    forn(i, cnt) p[i] = mp(a[i], b[i]);
    sort(p, p + cnt);
    int ind = 0;
    int clo = INF, chi = -INF;
    forn(i, ac) {
        while (ind < cnt && p[ind].first == i) {
            clo = min(clo, p[ind].second);
            chi = max(chi, p[ind].second);
            ++ind;
        }
        lo[i] = clo;
        hi[i] = chi;
    }
    ind = cnt - 1;
    clo = INF, chi = -INF;
    for (int i = ac - 1; i >= 1; --i) {
        while (ind >= 0 && p[ind].first == i) {
            clo = min(clo, p[ind].second);
            chi = max(chi, p[ind].second);
            --ind;
        }
        lo[i - 1] = max(lo[i - 1], clo);
        hi[i - 1] = min(hi[i - 1], chi);
    }
    LL res = 0;
    forn(i, ac - 1) {
        if (lo[i] < hi[i]) {
            res += (LL)(all[i + 1] - all[i]) * (bll[hi[i]] - bll[lo[i]]);
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", x + i, y + i);
        x[i] += 100000;
        y[i] += 100000;
    }
    LL ans = 0;
    forn(mod, 2) {
        cnt = 0;
        forn(i, n) if ((x[i] + y[i]) % 2 == mod) {
            a[cnt] = (x[i] + y[i]) / 2;
            b[cnt] = (x[i] - y[i] + 500000) / 2;
            ++cnt;
        }
        if (cnt) {
            ans += solve();
//            cerr << ans << " !" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}