#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, mi = 1;

void fillq(int m, int jmp = 0) {
    for(int i = m; i <= m + 2; i++) {
        for(int j = m; j <= m + 2; j++) {
            if(jmp && i == m && j == m) continue;
            if(i == m + 1 && j == m + 1) continue;
            printf("%d %d\n", i, j);
        }
    }
}

int main() {
    scanf("%lld", &n);

    printf("%d\n", 8 + 7 * n);
    fillq(mi);
    mi += 2;

    for(int i = 0; i < n; i++) {
        fillq(mi, 1);
        mi += 2;
    }

    return 0;
}