#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", (n > 1) + (m > 1));
    }
    return 0;
}