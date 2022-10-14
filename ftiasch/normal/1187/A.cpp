#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        printf("%d\n", std::max(std::min(a, n - b), std::min(b, n - a)) + 1);
    }
}