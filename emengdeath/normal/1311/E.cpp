#include <algorithm>
#include <cstdio>
using namespace std;
int getmn(int x, int n) {
    if (x * 2 >= n) return n;
    else
        return n + getmn(2 * x, n - 2 * x);
}
int getmx(int x, int n) {
    return n * (n + 1) / 2;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (getmn(1, n - 1) > m || getmx(1, n -1) < m) {
            puts("NO");
            continue;
        }
        printf("YES\n");
        int st = 1;
        n --;
        int dep = 0;
        int all = 1;
        while (n) {
            int last = all - st + 1;
            st = min(n, 2 * st);
            dep ++;
            while (st > 1&& n + getmx(st, n - (st)) < m) st --;
            for (int i = 1; i <= st; i += 2) {
                printf("%d ", last);
                if (i + 1 <= st)
                    printf("%d ", last);
                last ++;
            }
            m -= n;
            all += st;
            n -= st;
        }
        printf("\n");
    }
    return 0;
}