#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int c[200000], d[200000];
const int INF = int(1e9);

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", c + i, d + i);
    }
    int lo = -INF, hi = INF, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        bool ok = true;
        int cur = mid;
        forn(i, n) {
            if (d[i] == 2 && cur >= 1900) {
                ok = false;
                break;
            }
            cur += c[i];
        }
        if (ok) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if (hi == INF) {
        cout << "Infinity" << endl;
        return 0;
    }
    int cur = hi;
    forn(i, n) {
        if (d[i] == 1 && cur < 1900) {
            cout << "Impossible" << endl;
            return 0;
        }
        cur += c[i];
    }
    cout << cur << endl;
    return 0;
}