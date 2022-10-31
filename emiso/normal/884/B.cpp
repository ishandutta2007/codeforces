#include <bits/stdc++.h>

using namespace std;

int n, x, a, tot;

int main() {
    scanf("%d %d", &n, &x);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        tot += (a + (i > 0));
    }

    printf("%s\n", (tot == x) ? "YES" : "NO");
    return 0;
}