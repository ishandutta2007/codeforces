#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, tot;
int a[200000], t[200000], ind[200000];
pair<PII, int> p[200000];
int tmp[200000];

int ans[200000];

int main() {
    scanf("%d%d", &n, &tot);
    forn(i, n) scanf("%d%d", a + i, t + i);
    forn(i, n) p[i] = mp(mp(t[i], a[i]), i + 1);
    sort(p, p + n);
    forn(i, n) {
        t[i] = p[i].first.first;
        a[i] = p[i].first.second;
        ind[i] = p[i].second;
    }
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        int cnt = 0;
        int cost = 0;
        forn(i, n) if (mid <= a[i] && cnt < mid) {
            tmp[cnt++] = ind[i];
            cost += t[i];
        }
        if (cnt == mid && cost <= tot) {
            lo = mid;
            forn(i, mid) ans[i] = tmp[i];
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n%d\n", lo, lo);
    forn(i, lo) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}