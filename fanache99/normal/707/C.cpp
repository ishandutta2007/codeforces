#include <cstdio>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n, pow2, odd;
    scanf("%I64d", &n);
    if (n == 1 || n == 2) {
        printf("-1");
        return 0;
    }
    pow2 = 1;
    long long temp = n;
    while (temp % 2 == 0) {
        temp /= 2;
        pow2 *= 2;
    }
    odd = temp;
    if (odd != 1) {
        long long x = (odd * odd - 1) / 2, y = (odd * odd + 1) / 2;
        x *= pow2;
        y *= pow2;
        printf("%I64d %I64d", x, y);
    }
    else {
        long long x = (pow2 * pow2) / 4 - 1, y = (pow2 * pow2) / 4 + 1;
        printf("%I64d %I64d", x, y);
    }
    return 0;
}