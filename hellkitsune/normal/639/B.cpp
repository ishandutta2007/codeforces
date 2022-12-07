#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, d, h;

int main() {
    scanf("%d%d%d", &n, &d, &h);
    if (d == 1 && h == 1) {
        if (n == 2) {
            printf("1 2\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }
    if (d == 2 && h == 1) {
        for (int i = 2; i <= n; ++i) {
            printf("%d %d\n", 1, i);
        }
        return 0;
    }
    if (d > 2 * h || d < h) {
        printf("-1\n");
        return 0;
    }
    int cur = 2, pre = 1;
    REP(i, h) {
        printf("%d %d\n", pre, cur++);
        pre = cur - 1;
    }
    pre = 1;
    REP(i, d - h) {
        printf("%d %d\n", pre, cur++);
        pre = cur - 1;
    }
    while (cur <= n) {
        printf("%d %d\n", 2, cur++);
    }
    return 0;
}