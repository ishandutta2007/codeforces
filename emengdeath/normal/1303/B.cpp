#include<algorithm>
#include <cstdio>
using namespace std;
int t, n, g, b;
int main(){
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &n, &g, &b);
        int org = n;
        n = (n + 1) / 2;
        long long ans = 1ll * (n / g - (n % g == 0)) * (g+b);
        printf("%lld\n", max(ans + n % g + (n % g == 0) * g,1ll * org));
    }
    return 0;
}