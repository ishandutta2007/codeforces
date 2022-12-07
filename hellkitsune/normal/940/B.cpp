#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, k, a, b;

int main() {
    cin >> n >> k >> a >> b;
    LL ans = (n - 1) * a;
    if (k == 1) {
        cout << ans << endl;
        return 0;
    }
    LL cur = 0;
    while (n > 1) {
        LL rem = n % k;
        cur += rem * a;
        n -= rem;
        n /= k;
        cur += b;
        if (n > 0) {
            ans = min(ans, cur + (n - 1) * a);
        }
    }
    cout << ans << endl;
    return 0;
}