#include <cstdio>
#include <cstring>

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = k + 1; i >= 1; -- i) {
        printf("%d ", i);
    }
    for (int i = k + 2; i <= n; ++ i) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}