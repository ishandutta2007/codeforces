#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, w;
int a[1111];
LL sum[1111];

int main() {
    scanf("%d%d", &n, &w);
    forn(i, n) {
        scanf("%d", a + i);
    }
    sum[0] = 0;
    forn(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    LL mn = 0;
    forn(i, n + 1) {
        mn = min(mn, sum[i]);
    }
    forn(i, n + 1) {
        sum[i] -= mn;
    }
    LL mx = sum[0];
    forn(i, n + 1) {
        mx = max(mx, sum[i]);
    }
    LL ans = max(0ll, w - mx + 1);
    cout << ans << endl;
    return 0;
}