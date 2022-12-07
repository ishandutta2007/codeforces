#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, mx, cperf, cmin;
LL m;
int a[100000];

inline bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}
int ord[100000];

int f, ind = 0, level;
void updateMin() {
    while (true) {
        while (ind + 1 < f && level >= a[ord[ind + 1]]) ++ind;
        LL ad = m / (ind + 1);
        if (ind + 1 < f) ad = min(ad, (LL)a[ord[ind + 1]] - level);
        if (ad == 0) break;
        level += ad;
        m -= ad * (ind + 1);
    }
}

int ansPos, ansLevel;

int main() {
    scanf("%d%d%d%d", &n, &mx, &cperf, &cmin);
    cin >> m;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    f = n;
    for (int ii = n - 1; ii >= 0; --ii) {
        int i = ord[ii];
        if (mx - a[i] > m) break;
        m -= mx - a[i];
        f = ii;
    }
    if (f == 0) {
        LL ans = (LL)cperf * n + (LL)cmin * mx;
        cout << ans << endl;
        REP(i, n) printf("%d ", mx);
        printf("\n");
        return 0;
    }
    level = a[ord[0]];
    updateMin();
    LL ans = (LL)cperf * (n - f) + (LL)cmin * level;
    ansPos = f;
    ansLevel = level;
    while (f < n) {
        m += mx - max(a[ord[f]], level);
        ++f;
        updateMin();
        LL cur = (LL)cperf * (n - f) + (LL)cmin * level;
        if (cur > ans) {
            ans = cur;
            ansPos = f;
            ansLevel = level;
        }
    }
    cout << ans << endl;
    for (int i = ansPos; i < n; ++i) a[ord[i]] = mx;
    REP(i, n) a[i] = max(a[i], ansLevel);
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}