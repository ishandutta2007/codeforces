#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", (1 << n) - 1);
    }
    return 0;
}