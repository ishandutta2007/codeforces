#include <cassert>
#include <cstdio>
#include <cstring>

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    if (n == 1) {
        if (k == 0) {
            puts("1");
        } else {
            puts("-1");
        }
    } else if (k < n >> 1) {
        puts("-1");
    } else {
        int now = 0;
        for (int i = 0; i < n >> 1; ++ i) {
            int need = k / (n >> 1) + (i < k % (n >> 1));
            assert(need >= 1);
            int x = (now + need) / need;
            printf("%d %d ", x * need, (x + 1) * need);
            now = (x + 1) * need;
        }
        if (n & 1) {
            printf("%d ", now + 1);
        }
        puts("");
    }
    return 0;
}