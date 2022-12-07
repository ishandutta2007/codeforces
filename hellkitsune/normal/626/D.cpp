#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[2000];
int cnt[5000];
double p[5000], d[5000], nd[5000];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    forn(i, n) forn(j, i) {
        ++cnt[a[i] - a[j]];
    }
    int tot = n * (n - 1) / 2;
    forn(i, 5000) {
        d[i] = p[i] = (double)cnt[i] / tot;
    }
    forn(_, 2) {
        memset(nd, 0, sizeof nd);
        forn(i, 5000) forn(j, i) {
            nd[i - j] += d[i] * p[j];
        }
        memcpy(d, nd, sizeof d);
    }
    double ans = 0;
    for (int i = 1; i < 5000; ++i) {
        ans += d[i];
    }
    printf("%.15f\n", ans);
    return 0;
}