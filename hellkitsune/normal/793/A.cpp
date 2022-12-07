#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[100000];

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);
    for (int i = 1; i < n; ++i) {
        if (a[i] % k != a[0] % k) {
            printf("-1\n");
            return 0;
        }
    }
    int mn = a[0];
    forn(i, n) mn = min(mn, a[i]);
    LL ans = 0;
    forn(i, n) {
        ans += (a[i] - mn) / k;
    }
    cout << ans << endl;
    return 0;
}