#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", k * (n / k + 1));
}