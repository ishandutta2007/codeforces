#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if(n == 1) {
        printf("1 1\n%lld\n", -a[0]);
        puts("1 1\n0");
        puts("1 1\n0");
        return 0;
    }

    printf("1 %lld\n", n);
    for(int i = 0; i < n; i++) printf("%lld ", - a[i] * n);
    puts("");

    printf("1 %lld\n", n-1);
    for(int i = 0; i + 1 < n; i++) printf("%lld ", a[i] * (n - 1));
    puts("");

    printf("%lld %lld\n%lld\n", n, n, a[n-1] * (n - 1));
    return 0;
}