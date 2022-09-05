#include <bits/stdc++.h>
using namespace std;

int T;
long long a, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &a, &b);
        if (a - b > 1) {
            puts("NO");
        } else {
            a += b;
            bool flag = 1;
            for (long long i = 2; i * i <= a; i++) {
                if (!(a % i)) { flag = 0; break; }
            }
            puts(flag ? "YES" : "NO");
        }
    }
    return 0;
}