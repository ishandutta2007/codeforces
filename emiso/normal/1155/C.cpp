#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, x[300030], p[300030], g;

int main() {
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
        if(i == 1) g = (x[1] - x[0]);
        else g = __gcd(g, x[i] - x[i-1]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &p[i]);
        if(g % p[i] == 0) {
            puts("YES");
            printf("%lld %d\n", x[0], i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}