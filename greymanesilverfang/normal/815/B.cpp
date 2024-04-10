#include <stdio.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;

ll Combination[100005], inv[100005], *C = &Combination[1], ans = 0;

int main() {
    int n; scanf("%d", &n);
    int N = (n - 1) / 4 * 2;
    for (int i = -1; i <= N + 1; ++i)
        C[i]=i==-1||i==N+1?0:(i==0?1:C[i-1]*((N-i+1)*(inv[i]=i==1?1:(MOD*MOD-MOD/i*inv[MOD%i])%MOD)%MOD)%MOD);
    for (int i = 1; i <= n; ++i) {
        ll x; scanf("%lld", &x);
        (ans+=MOD*MOD+x*(n/2%2?(n%2?(i%2?C[i/2]-C[i/2-1]:2*C[i/2-1]):(i%2?C[i/2]:C[i/2-1])):(n%2?(i%2?C[i/2]:0):(i%2?C[i/2]+C[i/2-1]:-(C[i/2-1]+C[i/2-2])))))%=MOD;
    }
    printf("%lld", ans);
    return 0;
}