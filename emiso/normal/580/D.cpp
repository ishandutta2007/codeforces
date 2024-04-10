#include <bits/stdc++.h>

#define MN 18

using namespace std;
typedef long long ll;

int n,m,k;
ll c[MN], adj[MN][MN], dp[1<<(MN+1)][MN], best = -1,x,y,v;

void solve() {
    for(int i=0;i<n;i++)
        dp[1<<i][i] = c[i];

    for(int bm = 1; bm < 1<<(n+1); bm++)
        for(int i=0;i<n;i++)
            if(bm & (1<<i)) {
                for(int j=0;j<n;j++)
                    if(!(bm & (1<<j) ))
                        dp[bm|(1<<j)][j] = max(dp[bm|(1<<j)][j],
                                               dp[bm][i] + adj[i][j] + c[j]);

                if(__builtin_popcount(bm) == m)
                    best = max(best, dp[bm][i]);
            }
}

int main() {
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0;i<n;i++)
        scanf("%lld",&c[i]);

    for(int i=0;i<k;i++) {
        scanf("%d %d %d",&x,&y,&v);
        adj[--x][--y] = v;
    }

    solve();

    printf("%lld\n",best);

    return 0;
}