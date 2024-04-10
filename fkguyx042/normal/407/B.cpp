#include <cstdio>

using namespace std;

const int maxn = 1000 + 10;
const int mod = 1000000000 + 7;

int main()
{
    int n, p[maxn];
    long long d[maxn];
    while(scanf("%d", &n) == 1) {
        d[1] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", p+i);
            d[i+1] = (2 * d[i] + 2 - d[p[i]] + mod) % mod;
        }
        printf("%I64d\n", d[n+1]);
    }
    return 0;
}