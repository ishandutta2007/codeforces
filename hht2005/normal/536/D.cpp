#include<bits/stdc++.h>
using namespace std;
#define lb(c,cnt,x) lower_bound(c+1,c+cnt+1,x)-c
const int N=2010;
int w[N][N],las1[N],las2[N],siz[N][N],p[N],n;
long long dS[N],dT[N],sum[N][N],dp[2][N][N],cs[N],ct[N];
bool f[N];
void get(int s,long long dis[N]) {
	memset(f,0,sizeof(f));
	memset(dis,0x3f,8*N);
	dis[s]=0;
	for(int i=1;i<=n;i++) {
		int I=0;
		for(int j=1;j<=n;j++)
			if(!f[j]&&(!I||dis[I]>dis[j]))
				I=j;
		f[I]=1;
		for(int j=1;j<=n;j++)
			if(~w[I][j]&&dis[j]>dis[I]+w[I][j])
				dis[j]=dis[I]+w[I][j];
	}
}
int main() {
	memset(w,-1,sizeof(w));
	int m,s,t,a,b,v;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&v);
		if(w[a][b]==-1||w[a][b]>v)
			w[a][b]=w[b][a]=v;
	}
	get(s,dS);
	get(t,dT);
	int c1=0,c2=0;
	long long Sum=0;
	for(int i=1;i<=n;i++) {
		cs[++c1]=dS[i];
		ct[++c2]=dT[i];
	}
	sort(cs+1,cs+c1+1);
	sort(ct+1,ct+c2+1);
	c1=unique(cs+1,cs+c1+1)-cs-1;
	c2=unique(ct+1,ct+c2+1)-ct-1;
	for(int i=1;i<=n;i++) {
		dS[i]=lb(cs,c1,dS[i]);
		dT[i]=lb(ct,c2,dT[i]);
		sum[dS[i]-1][dT[i]-1]+=p[i];
		siz[dS[i]-1][dT[i]-1]++;
		Sum+=p[i];
	}
	for(int i=c1;i>=0;i--)
		for(int j=c2;j>=0;j--) {
			sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
			siz[i][j]+=siz[i+1][j]+siz[i][j+1]-siz[i+1][j+1];
		}
	for(int i=0;i<=c1;i++) {
		for(int j=0;j<=c2;j++) {
			sum[i][j]=Sum-sum[i][j];
			siz[i][j]=n-siz[i][j];
		}
	}
	memset(dp[0],0x3f,sizeof(dp[0]));
	memset(dp[1],0xc0,sizeof(dp[1]));
	for(int i=0;i<=c2;i++)las1[i]=c1;
	for(int i=0;i<=c1;i++)las2[i]=c2;
	for(int i=c1;i>=0;i--)
		for(int j=c2;j>=0;j--) {
			if(siz[i][j]==n) {
				dp[0][i][j]=min(dp[0][i][j+1],-sum[i][j]);
				dp[1][i][j]=max(dp[1][i+1][j],+sum[i][j]);
				continue;
			}
			while(siz[i][j]!=siz[las1[j]-1][j])las1[j]--;
			while(siz[i][j]!=siz[i][las2[i]-1])las2[i]--;
			dp[0][i][j]=dp[1][las1[j]][j]-sum[i][j];
			dp[1][i][j]=dp[0][i][las2[i]]+sum[i][j];
			if(i==0&&j==0)Sum=dp[0][0][0];
			dp[0][i][j]=min(dp[0][i][j+1],dp[0][i][j]-sum[i][j]);
			dp[1][i][j]=max(dp[1][i+1][j],dp[1][i][j]+sum[i][j]);
		}
	if(Sum==0)puts("Flowers");
	if(Sum>0)puts("Break a heart");
	if(Sum<0)puts("Cry");
	return 0;
}