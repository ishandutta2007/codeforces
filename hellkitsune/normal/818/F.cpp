#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    int tc;
    mt19937 mt(time(0));
    scanf("%d", &tc);
    forn(test, tc) {
        int n;
        scanf("%d", &n);
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = ((unsigned)lo + hi + 1) >> 1;
            int rem = n - 1 - mid;
            rem -= 4;
            if (rem < 0) {
                hi = mid - 1;
                continue;
            }
            int need = mid - 1;
            rem /= 2;
            if ((LL)(rem + 1) * (rem + 2) / 2 - 1 >= need) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        printf("%u\n", (unsigned)lo + n - 1);
    }
    return 0;
}