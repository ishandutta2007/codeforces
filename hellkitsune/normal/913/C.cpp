#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL need;
LL c[31];

int main() {
    cin >> n >> need;
    forn(i, 31) {
        c[i] = LL(1e18);
    }
    forn(i, n) cin >> c[i];
    forn(i, 30) c[i + 1] = min(c[i + 1], c[i] * 2);
    LL ans = LL(1e18);
    LL cur = 0;
    for (int i = 30; i >= 0; --i) {
        if (need & (1 << i)) {
            cur += c[i];
        } else {
            ans = min(ans, cur + c[i]);
        }
    }
    ans = min(ans, cur);
    cout << ans << endl;
    return 0;
}