#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, h;
int a[100000];

int main() {
    scanf("%d%d%d", &n, &h, &k);
    REP(i, n) scanf("%d", a + i);
    LL ans = 0;
    int pos = 0, rem = 0;
    while (true) {
        while (pos < n && a[pos] + rem <= h) {
            rem += a[pos];
            ++pos;
        }
        if (rem >= k) {
            ans += rem / k;
            rem %= k;
        } else {
            ++ans;
            rem = 0;
        }
        if (pos == n && rem == 0) break;
    }
    cout << ans << endl;
    return 0;
}