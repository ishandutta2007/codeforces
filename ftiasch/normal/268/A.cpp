#include <cstdio>
#include <cstring>

const int N = 30;

int n, a[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", a + i, b + i);
    }
    int answer = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i != j) {
                answer += a[i] == b[j];
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}