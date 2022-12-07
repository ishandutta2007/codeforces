#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p;
int a[100000], b[100000];

int main() {
    scanf("%d%d", &n, &p);
    forn(i, n) scanf("%d%d", a + i, b + i);
    LL perSec = -p;
    forn(i, n) perSec += a[i];
    if (perSec <= 0) {
        cout << -1 << endl;
        return 0;
    }
    double lo = 0, hi = 2e10, mid;
    forn(_, 100) {
        mid = (lo + hi) / 2;
        double need = 0;
        forn(i, n) {
            need += max(0.0, a[i] * mid - b[i]);
        }
        if (need > p * mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.15f\n", lo);
    return 0;
}