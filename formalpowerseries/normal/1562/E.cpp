#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char a[5005];
int sa[5005],height[5005],cnt[5005],x[5005],tmp1[5005],Rank[5005],n,m;
void MakeSuffixArray()
{
	m=127;
	for(int i=1;i<=n;++i)	++cnt[x[i]=a[i]];
	for(int i=2;i<=m;++i)	cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)	sa[cnt[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int tmp=0;
		for(int i=n-k+1;i<=n;++i)	tmp1[++tmp]=i;
		for(int i=1;i<=n;++i)	if(sa[i]>k)	tmp1[++tmp]=sa[i]-k;
		for(int i=1;i<=m;++i)	cnt[i]=0;
		for(int i=1;i<=n;++i)	++cnt[x[i]];
		for(int i=2;i<=m;++i)	cnt[i]+=cnt[i-1];
		for(int i=n;i;--i)	sa[cnt[x[tmp1[i]]]--]=tmp1[i],tmp1[i]=0;
		swap(x,tmp1);
		tmp=1;
		x[sa[1]]=1;
		for(int i=2;i<=n;++i)	x[sa[i]]=(tmp1[sa[i]]==tmp1[sa[i-1]] && tmp1[sa[i]+k]==tmp1[sa[i-1]+k])?tmp:++tmp;
		if(tmp==n)	break;
		m=tmp; 
	}
}
void MakeHeightArray()
{
	int k=0;
	for(int i=1;i<=n;++i)	Rank[sa[i]]=i;
	for(int i=1;i<=n;++i)
	{
		if(Rank[i]==1)	continue;
		if(k)	--k;
		int j=sa[Rank[i]-1];
		while(j+k<=n && i+k<=n && a[i+k]==a[j+k])	++k;
		height[Rank[i]]=k;
	}
}
int dp[5005],st[5005][15],lgs[5005];
int range(int l,int r)
{
	int k=lgs[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=2;i<=5000;++i)	lgs[i]=lgs[i>>1]+1;
	while(T-->0)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		memset(sa,0,sizeof cnt);
		memset(height,0,sizeof cnt);
		memset(x,0,sizeof cnt);
		memset(tmp1,0,sizeof cnt);
		memset(Rank,0,sizeof cnt);
		memset(st,0,sizeof st);
		scanf("%s",a+1);
		MakeSuffixArray();
		MakeHeightArray();
		for(int i=1;i<=n;++i)	dp[i]=n-i+1;
		memset(st,0,sizeof st);
		for(int i=1;i<=n;++i)	st[i][0]=height[i];
		for(int j=1;j<=14;++j)	for(int i=1;i+(1<<j)-1<=n;++i)	st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<i;++j)
			{
				int I=Rank[i],J=Rank[j];
				int pk=range(min(I,J)+1,max(I,J));
				if(pk!=n-i+1 && a[j+pk]<a[i+pk])	dp[i]=max(dp[i],dp[j]+n-i+1-pk);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)	ans=max(ans,dp[i])/*,printf("%d ",dp[i])*/;
//		puts("");
		printf("%d\n",ans);
	}
	return 0;
}