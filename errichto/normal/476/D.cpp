#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", (n * 6 - 1) * k);
    int x = 0;
    for(int i = 0; i < n; ++i) {
        printf("%d %d %d %d\n", k * (x + 1), k * (x + 2), k * (x + 3), k * (x + 5));
        x += 6;
    }
}