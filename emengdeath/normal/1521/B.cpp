#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
int a[100001];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n - 1);
        int x = 1;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            if (a[i] < a[x]) x = i;
        }
        for (int i = 1; i <= n; i ++)
            if (i != x) {
                if ((i - x) & 1)
                    printf("%d %d %d %d\n", i, x, a[x] + 1, a[x]);
                else
                    printf("%d %d %d %d\n", i, x, a[x], a[x]);
            }
    }
    return 0;
}