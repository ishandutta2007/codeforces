#include <bits/stdc++.h>
using namespace std;

int T, a1, a2, a3;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a1, &a2, &a3);
        int s = a1 + a3 - 2 * a2;
        if (s >= 0) printf("%d\n", min(abs(s % 3), abs(s % 3 - 3)));
        else printf("%d\n", min(abs(s % 3), abs(s % 3 + 3)));
    }
    return 0;
}