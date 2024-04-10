#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a[101][101];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            puts("1");
            continue;
        }
        if (n == 2) {
            puts("-1");
            continue;
        }
        int x = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (x & 1) {
                    printf("%d ", x);
                    x+= 2;
                    if (x > n * n) {
                        x = 2;
                    }
                } else {
                    printf("%d ", x);
                    x += 2;
                }
            }
            puts("");
        }
    }
    return 0;
}