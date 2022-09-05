#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        if (n % 2050) { puts("-1"); continue; }
        n /= 2050;
        int s = 0;
        while (n) s += n % 10, n /= 10;
        printf("%d\n", s);
    }
    return 0;
}