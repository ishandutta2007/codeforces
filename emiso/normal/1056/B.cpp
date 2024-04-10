#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, quant[1010];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 1; i <= m; i++) {
        quant[i*i%m] += n / m + (n % m >= i);
    }
    
    for(int i = 0; i < m; i++) {
        ans += quant[i] * quant[(m - i) % m];
    }

    printf("%lld\n", ans);
    return 0;
}