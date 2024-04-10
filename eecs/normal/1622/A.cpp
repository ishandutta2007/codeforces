#include <bits/stdc++.h>
using namespace std;

int T, l1, l2, l3;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &l1, &l2, &l3);
        if (l1 == l2 + l3 || l2 == l1 + l3 || l3 == l1 + l2 || l1 == l2 && l3 % 2 == 0 || l2 == l3 && l1 % 2 == 0 || l1 == l3 && l2 % 2 == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}