#include <cstdio>
#include <cstring>

const int N = 3000;

int n, m, a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", b + i);
    }
    int result = n;
    for (int i = 0, j = 0; i < n; ++ i) {
        while (j < m && a[i] > b[j]) {
            j ++;
        }
        if (j < m) {
            j ++;
            result --;
        }
    }
    printf("%d\n", result);
    return 0;
}