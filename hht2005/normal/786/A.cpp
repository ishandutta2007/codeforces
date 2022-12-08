#include<bits/stdc++.h>
using namespace std;
const int N=7010;
int dp[N][2],s[N][2],k[2],deg[N][2],f[N][2],n,q[2*N];
int main() {
	scanf("%d",&n);
	for(int i=0;i<2;i++) {
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++)
			scanf("%d",s[j]+i);
	}
	q[1]=2,q[2]=3;
	int h=1,e=2;
	for(int i=2;i<=n;i++) {
		deg[i][0]=k[0],deg[i][1]=k[1];
		dp[i][0]=dp[i][1]=2;
	}
	f[1][0]=f[1][1]=1;
	while(h<=e) {
		int x=q[h]>>1,v=q[h]&1;
		h++;
		for(int i=1;i<=k[v^1];i++) {
			int y=(x-s[i][v^1]+n-1)%n+1;
			if(f[y][v^1])continue;
			if(!dp[x][v]) {
				q[++e]=y<<1|(v^1);
				dp[y][v^1]=1;
				f[y][v^1]=1;
			} else {
				deg[y][v^1]--;
				if(!deg[y][v^1]) {
					q[++e]=y<<1|(v^1);
					dp[y][v^1]=0;
					f[y][v^1]=1;
				}
			}
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=2;j<=n;j++)
			printf(dp[j][i]==2?"Loop ":(dp[j][i]==1?"Win ":"Lose "));
		puts("");
	}
	return 0;
}