#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ///5x13
    ///5x1 = 5x5 = 5x9 = 5x13 = 5
    ///5x7 = 5x3
    while(1) {
        if(n < m) swap(n, m);
        if(m <= 1) break;
        n = ((n - 1) % (m - 1)) + 1;
    }

    printf("%d\n", n);

    return 0;
}