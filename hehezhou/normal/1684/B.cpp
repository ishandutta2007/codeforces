#include <bits/stdc++.h>
using namespace std;
void rmain() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    long long y = b;
    long long x = y * int(1e9) + a;
    long long z = c;
    printf("%lld %lld %lld\n", x, y, z);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}