#include <stdio.h>
#include <string.h>
using namespace std;

int s[200005], Lcnt[200005], Rcnt[200005];

int main() {
    int n, k, q; scanf("%d%d%d", &n, &k, &q);
    memset(Lcnt, 0, sizeof(Lcnt));
    memset(Rcnt, 0, sizeof(Rcnt));
    for (int i = 1; i <= n; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        Lcnt[l]++; Rcnt[r]++;
    }
    int cnt = 0; s[0] = 0;
    for (int i = 1; i <= 200000; ++i)
        s[i] = s[i - 1] + ((cnt += Lcnt[i] - Rcnt[i - 1]) >= k);
    while (q--) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%d\n", s[b] - s[a - 1]);
    }
    return 0;
}