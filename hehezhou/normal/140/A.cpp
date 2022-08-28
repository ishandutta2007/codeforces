#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, R, r;
    scanf("%d%d%d", &n, &R, &r);
    if (R < r) return puts("NO"), 0;
    if (R < r + r) return puts(n == 1 ? "YES" : "NO"), 0;
    R -= r;
    double alpha = asin(1. * r / R);
    if (n <= floor((acos(-1) + 1e-8) / alpha)) puts("YES");
    else puts("NO");
}