#include <stdio.h>

int n,v[100100],sum[100100],total,ans;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        sum[i] = sum[i-1] + v[i];
    }
    for(int i=1;i<n;i++)
        if(sum[i] * 2 == sum[n]) ans++;
    printf("%d\n",ans);
    return 0;
}