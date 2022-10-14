#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int s, a, b, c;
        scanf("%d%d%d%d", &s, &a, &b, &c);
        int paid = s / c;
        printf("%lld\n", paid + 1LL * paid / a * b);
    }
}