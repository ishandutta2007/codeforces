#include <stdio.h>

int n, a;
int o;
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) o++;
        else ans += o;
    }

    printf("%I64d\n", ans);
}