#include <algorithm>
#include <cstdio>
using namespace std;
int a[100000];
int main() {
    int n;
    scanf("%d", &n);
    int x = 1;
    for (int i = 2; i <= n; i ++) {
        printf("? %d %d\n", x, i);
        printf("? %d %d\n", i, x);
        fflush(stdout);
        int v1, v2;
        scanf("%d", &v1);
        scanf("%d", &v2);
        if (v1 > v2) {
            a[x] = v1;
            x = i;
        } else {
            a[i] = v2;
        }
    }
    a[x] = n;
    printf("!");
    for (int i = 1; i <= n; i ++)
        printf(" %d", a[i]);
    puts("");
    return 0;
}