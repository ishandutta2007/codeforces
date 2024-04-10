#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 3e9;

int tt;
LL x, y, p, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> tt;
    forn(test, tt) {
        cin >> x >> y >> p >> q;
        LL lo = 1, hi = INF, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            LL pp = p * mid;
            LL qq = q * mid;
            if (x <= pp && y - x <= qq - pp) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo == INF) {
            cout << "-1\n";
        } else {
            LL ans = q * lo - y;
            cout << ans << '\n';
        }
    }

    return 0;
}