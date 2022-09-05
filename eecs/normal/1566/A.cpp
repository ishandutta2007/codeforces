#include <bits/stdc++.h>
using namespace std;

int T, n, s;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &s);
        int t = (n + 2) / 2;
        printf("%d\n", s / t);
    }
    return 0;
}