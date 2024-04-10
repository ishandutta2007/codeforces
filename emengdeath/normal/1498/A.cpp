#include <iostream>
#include <cmath>
using namespace std;
long long sum(long long x) {
    long long v = 0;
    while (x != 0) v += x % 10, x /= 10;
    return v;
}
long long gcd(long long x, long long y) {
    return x == 0 ? y : gcd(y % x, x);
}
bool check(long long x) {
    return gcd(x, sum(x)) > 1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        long long x;
        scanf("%lld", &x);
        while (!check(x)) ++x;
        printf("%lld\n", x);
    }
    return 0;
}