#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p, q, r;
int a[100000];
int pmn[100000], pmx[100000], smn[100000], smx[100000];

int main() {
    scanf("%d%d%d%d", &n, &p, &q, &r);
    forn(i, n) scanf("%d", a + i);
    pmn[0] = pmx[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pmn[i] = min(pmn[i - 1], a[i]);
        pmx[i] = max(pmx[i - 1], a[i]);
    }
    smn[n - 1] = smx[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        smn[i] = min(smn[i + 1], a[i]);
        smx[i] = max(smx[i + 1], a[i]);
    }
    LL ans = -LL(5e18);
    forn(i, n) {
        LL cur = max((LL)pmn[i] * p, (LL)pmx[i] * p) + (LL)a[i] * q +
            max((LL)smn[i] * r, (LL)smx[i] * r);
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}