#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int s, x, xx;
int t, tt;
int p, d;

int solve() {
    if (xx < x) {
        x = s - x;
        xx = s - xx;
        p = s - p;
        d *= -1;
    }
    if (d == 1) {
        if (p <= x) {
            return tt * (xx - p);
        }
        return tt * (xx - p + 2 * s);
    } else {
        return tt * (p + xx);
    }
}

int main() {
    cin >> s >> x >> xx;
    cin >> tt >> t;
    cin >> p >> d;
    int ans = t * abs(xx - x);
    ans = min(ans, solve());
    cout << ans << endl;
    return 0;
}