#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
int from[100] = {};

int main() {
    scanf("%d%d", &n, &q);
    forn(i, q) {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        int cnt = 0;
        forn(i, n) if (from[i] <= t) {
            ++cnt;
        }
        if (cnt < k) {
            printf("-1\n");
            continue;
        }
        int sum = 0;
        forn(i, n) if (from[i] <= t) {
            sum += i + 1;
            from[i] = t + d;
            --k;
            if (k == 0) {
                break;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}