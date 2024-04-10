#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int q, n;

int main() {
    scanf("%d", &q);
    forn(_, q) {
        scanf("%d", &n);
        int ans = 0;
        if (n % 2 == 1) {
            if (n < 9) {
                printf("-1\n");
                continue;
            }
            n -= 9;
            ans += 1;
        }
        if (n % 4 != 0) {
            if (n < 6) {
                printf("-1\n");
                continue;
            }
            n -= 6;
            ans += 1;
        }
        assert(n % 4 == 0);
        ans += n / 4;
        printf("%d\n", ans);
    }
    return 0;
}