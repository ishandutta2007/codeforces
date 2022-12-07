#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[500000];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    LL sum = 0;
    REP(i, n) sum += a[i];
    int mn = sum / n;
    int mx = mn + (sum % n > 0);
    int amn = a[0], amx = a[0];
    for (int i = 1; i < n; ++i) {
        amn = min(amn, a[i]);
        amx = max(amx, a[i]);
    }
    int lo = mx, hi = amx, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        int rem = k;
        REP(i, n) if (a[i] > mid) {
            rem -= a[i] - mid;
            if (rem < 0) break;
        }
        if (rem < 0) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    mx = lo;
    lo = amn, hi = mn;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        int rem = k;
        REP(i, n) if (a[i] < mid) {
            rem -= mid - a[i];
            if (rem < 0) break;
        }
        if (rem < 0) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    mn = lo;
    printf("%d\n", mx - mn);
    return 0;
}