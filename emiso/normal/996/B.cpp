#include <bits/stdc++.h>

using namespace std;

int n, a, g, t = 1111111111;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        a -= i; a = max(a, 0);
        int tmp = i + n * ((a + n - 1) / n);
        if(tmp < t) {
            t = tmp;
            g = i + 1;
        }
    }

    printf("%d\n", g);
    return 0;
}