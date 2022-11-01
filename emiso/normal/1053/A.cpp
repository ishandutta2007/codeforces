#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, k, ab, N, M;

void fim(int a, int b) {
    puts("YES");
    printf("0 0\n");
    printf("%d 0\n", a);
    printf("0 %d\n", b);
    exit(0);
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    N = n; M = m;

    if((2LL * n * m) % k) {
        puts("NO");
        return 0;
    }

    ll ab = 2LL*n*m/k;
    ll g = __gcd(n, k);
    n /= g; k /= g;
    g = __gcd(m, k);
    m /= g; k /= g;

    if(k == 1) {
        if(2*n <= N) {
            fim(2*n, m);
        } else if(2*m <= M) {
            fim(n, 2*m);
        }
    } else {
        fim(n, m);
    }

    puts("NO");
    return 0;
}