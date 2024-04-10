#include <bits/stdc++.h>
using namespace std;

long long n, fib[110];

int main() {
    scanf("%lld", &n), n--;
    fib[1] = 1, fib[2] = 2;
    for (int i = 3; i <= 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 1; ; i++) {
        if (n <= fib[i]) printf("%d\n", i), exit(0);
        n -= fib[i];
    }
    return 0;
}