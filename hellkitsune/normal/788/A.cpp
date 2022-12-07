#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

int n;
int a[100005];
LL sum[100005];
LL mx, mn;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        a[i] = abs(a[i] - a[i + 1]);
    }
    sum[0] = 0;
    forn(i, n - 1) if (i & 1) {
        sum[i + 1] = sum[i] - a[i];
    } else {
        sum[i + 1] = sum[i] + a[i];
    }
    mx = -INF;
    mn = INF;
    LL ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i & 1) {
            ans = max(ans, -mn + sum[i]);
        } else {
            ans = max(ans, mx - sum[i]);
        }
        mn = min(mn, sum[i]);
        mx = max(mx, sum[i]);
    }
    cout << ans << endl;
    return 0;
}