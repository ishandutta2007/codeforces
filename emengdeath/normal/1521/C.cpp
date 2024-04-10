#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
int TAG;
int a[10001];
int ask(int sig, int x, int y, int z) {
    printf("? %d %d %d %d\n", sig, x, y, z);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        ++TAG;
        int x = 0;
        for (int i = 1; i + 1 <= n; i += 2) {
            int v = ask(2, i, i + 1, 1);
            if (v == 1) {
                x = i;
                break;
            } else {
                if (v == 2) {
                    if (ask(2, i + 1, i, 1) == 1) {
                        x = i + 1;
                        break;
                    }
                }
            }
        }
        if (!x) x = n;
        for (int i = 1; i <= n; i ++)
            if (i == x) {
                a[i] = 1;
            } else {
                a[i] = ask(1, x, i, n - 1);
            }
        printf("!");
        for (int i = 1; i <= n; i++)
            printf(" %d", a[i]);
        puts("");
        fflush(stdout);
    }
    return 0;
}