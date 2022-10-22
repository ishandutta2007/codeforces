#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    int ans[n];
    int pos = 0;
    for (int i = 0; i < n; i++) {
        while (pos > 0 && a[i] == ans[pos-1]) {
            a[i]++;
            pos--;
        }
        ans[pos++] = a[i];
    }

    printf("%d\n", pos);
    for (int i = 0; i < pos; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}