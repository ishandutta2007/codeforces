#include <stdio.h>
using namespace std;

int main() {
    int n, m, p[10005];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    while (m--) {
        int l, r, x, cnt = 0;
        scanf("%d%d%d", &l, &r, &x);
        for (int i = l; i <= r; ++i)
            cnt += (p[i] < p[x]);
        printf("%s\n", cnt + l == x ? "Yes" : "No");
    }
    return 0;
}