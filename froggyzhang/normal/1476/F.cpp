#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
int dp[N],a[N],n,lg[N],pmx[N];
int f[N][20];
inline int Query(int l,int r){
	if(l>r)return 0;
	int k=lg[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int pre[N],t[N];
void dfs(int u){
	if(!u)return;
	dfs(pre[u]);
	for(int i=pre[u]+1;i<u;++i)putchar('R');
	putchar(t[u]==1?'R':'L');
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		f[i][0]=i+a[i];
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	dp[0]=pmx[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=0;
		if(dp[i-1]<i){
			if(dp[i-1]>=i-a[i]-1)dp[i]=max(dp[i-1],i-1);
			pre[i]=i-1,t[i]=-1;
		}
		else{
			dp[i]=max(dp[i-1],i+a[i]);
			pre[i]=i-1,t[i]=1;
		}
		int u=lower_bound(pmx,pmx+i,i-a[i]-1)-pmx;
		if(u<i){
			int R=max(dp[u],Query(u+1,i-1));
			if(R>dp[i]){
				dp[i]=R,pre[i]=u,t[i]=-1;
			}
		}
		pmx[i]=max(pmx[i-1],dp[i]);
	}
	if(dp[n]<n)return (void)printf("NO\n");
	printf("YES\n");
	dfs(n);
	printf("\n");
}
int main(){
	for(int i=2;i<=300001;++i){
		lg[i]=lg[i>>1]+1;
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}