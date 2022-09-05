#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 2; i <= n + 1; i++) printf("%d ", i * i);
        putchar('\n');
    }
    return 0;
}