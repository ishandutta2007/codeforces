#include <bits/stdc++.h>
#define maxn 500005
#define ll long long

const int mod=998244353;
int v[maxn],d[maxn],dp[maxn],sum[maxn],l[maxn],r[maxn],x[maxn],rk[maxn],n,k,m;
int cmp(int a,int b){return r[a]<r[b];}

int work(int p){
	std::memset(d,0,sizeof(d));
	std::memset(dp,0,sizeof(dp));
	std::memset(sum,0,sizeof(sum));
	for(int i=1;i<=m;++i){
		v[i]=((x[i]>>p)&1);
		d[l[i]]+=v[i];d[r[i]+1]-=v[i];
	}for(int i=1;i<=n;++i)d[i]+=d[i-1];
	for(int i=1;i<=n;++i)d[i]=(!(!d[i]));d[n+1]=0;
	int p1=0,max=0;
	sum[0]=dp[0]=1;
	for(int i=1;i<=n+1;++i){
		while(p1<m&&r[rk[p1+1]]<i){
			p1++;if(v[rk[p1]]==1)continue;
			max=std::max(max,l[rk[p1]]);
		}
		if(d[i])dp[i]=0;
		else dp[i]=(sum[i-1]-(max>0?sum[max-1]:0)+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	return dp[n+1];
}
	
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&l[i],&r[i],&x[i]);
		rk[i]=i;
	}std::sort(rk+1,rk+m+1,cmp);
	int ans=1;
	for(int i=0;i<k;++i)ans=((ll)ans*work(i))%mod;
	printf("%d",ans);
	return 0;
}