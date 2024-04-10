#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long lld;
const int MOD = 1e9+7;
const int N = 2222;
int n,K;
lld sum[N],tail[N],f[N][N];
char s[N];
lld work() {
    lld ret = 0;
    tail[n+1] = 1;
    for (int i = n; i >= 1; i --)
        tail[i] = tail[i+1]*(s[i]-'a'+1)%MOD;
    if (K==0) return tail[1];
    f[0][0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i ++) {
        int dt = n-i+1;
        for (int j = 0; j <= K; j ++) {
            for (int k = i-1; k>=0 && (i-k)*dt<=j; k--) {
                f[i][j] = (f[i][j]+f[k][j-(i-k)*dt])%MOD;
            }
            f[i][j] = f[i][j]*('z'-s[i])%MOD;
        }
        ret = (ret+f[i][K]*tail[i+1]%MOD)%MOD;
        for (int j = 0; j <= K; j ++) {
            f[i][j] = (f[i][j]+sum[j]*(s[i]-'a')%MOD)%MOD;
            sum[j] = (sum[j]+f[i][j])%MOD;
        }
    }
    return ret;
}
int main() {
    scanf("%d%d%s",&n,&K,s+1);
    printf("%I64d\n",work());
    return 0;
}