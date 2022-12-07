#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int x, s;
int a[200005], b[200005], c[200005], d[200005];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &x, &s);
    forn(i, m) scanf("%d", a + i);
    forn(i, m) scanf("%d", b + i);
    forn(i, k) scanf("%d", c + i);
    forn(i, k) scanf("%d", d + i);
    LL ans = (LL)n * x;
    forn(i, m) {
        if (b[i] > s) {
            continue;
        }
        int rem = s - b[i];
        int ind = lower_bound(d, d + k, rem + 1) - d;
        --ind;
        int cnt = n;
        if (ind != -1) {
            cnt = max(0, n - c[ind]);
        }
        ans = min(ans, (LL)cnt * a[i]);
    }
    forn(i, k) {
        if (d[i] > s) {
            continue;
        }
        int cnt = max(0, n - c[i]);
        ans = min(ans, (LL)cnt * x);
    }
    cout << ans << endl;
    return 0;
}