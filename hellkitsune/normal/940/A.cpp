#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, d;
int a[100];

int main() {
    scanf("%d%d", &n, &d);
    forn(i, n) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans = 0;
    forn(i, n) for (int j = i; j < n; ++j) {
        int mn = 1234;
        int mx = -1234;
        for (int k = i; k <= j; ++k) {
            mn = min(mn, a[k]);
            mx = max(mx, a[k]);
        }
        if (mx - mn <= d) {
            ans = max(ans, j - i + 1);
        }
    }
    ans = n - ans;
    cout << ans << endl;
    return 0;
}