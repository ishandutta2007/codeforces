#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;

int main() {
    scanf("%d", &tt);
    REP(test, tt) {
        scanf("%d", &n);
        LL ans = (LL)n * (n + 1) / 2;
        for (int x = 1; x <= n; x <<= 1) {
            ans -= x << 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}