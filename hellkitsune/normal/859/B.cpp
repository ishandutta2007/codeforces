#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    scanf("%d", &n);
    int ans = int(1e9);
    for (int x = 1; x <= n; ++x) {
        int y = (n + x - 1) / x;
        ans = min(ans, 2 * (x + y));
    }
    cout << ans << endl;
    return 0;
}