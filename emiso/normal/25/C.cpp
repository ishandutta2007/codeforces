#include <bits/stdc++.h>

#define MN 303

using namespace std;

int r[MN][MN],rl[MN][MN];
long long ans;

int main() {
    int n,k,a,b,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&r[i][j]);
            rl[i][j] = r[i][j];
        }
    }
    scanf("%d",&k);
    for(int K=0;K<k;K++) {
        ans = 0;
        scanf("%d %d %d",&a,&b,&c);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(rl[i][j] > rl[i][a] + c + rl[b][j])
                    rl[i][j] = rl[j][i] = rl[i][a] + c + rl[b][j];
                if(rl[i][j] > rl[i][b] + c + rl[a][j])
                    rl[i][j] = rl[j][i] = rl[i][b] + c + rl[a][j];
                ans += (long long) rl[i][j];
            }
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}