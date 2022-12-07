#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[1000005];
int nx[30000005][2] = {}, cnt[30000005] = {};
int nodes = 1;

int main() {
    scanf("%d%d", &n, &k);
    a[0] = 0;
    REP(i, n) {
        int x;
        scanf("%d", &x);
        a[i + 1] = a[i] ^ x;
    }
    LL ans = 0;
    REP(z, n + 1) {
        int val = a[z];

        int pos = 0;
        for (int i = 29; i >= 0; --i) {
            int cur = (val & (1 << i)) > 0;
            int kval = (k & (1 << i)) > 0;
            int newPos = 0;
            REP(j, 2) {
                if ((cur ^ j) > kval) {
                    ans += cnt[nx[pos][j]];
                } else if ((cur ^ j) == kval) {
                    newPos = nx[pos][j];
                }
            }
            if (!newPos) {
                pos = 0;
                break;
            }
            pos = newPos;
        }
        if (pos != 0) ans += cnt[pos];

        pos = 0;
        for (int i = 29; i >= 0; --i) {
            int cur = (val & (1 << i)) > 0;
            if (!nx[pos][cur]) {
                nx[pos][cur] = nodes++;
            }
            pos = nx[pos][cur];
            ++cnt[pos];
        }
    }
    cout << ans << endl;
    return 0;
}