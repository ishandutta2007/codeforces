#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
int n,m,len[1001],pos[11],sum[11],dp[1001][1001],c[11],ord[1001][1001],ans;
char b[1001][1001],a[1001];
int vis[1001];
vector<int> t[11];
inline bool check(int x,int y)
{
	if(x==len[0]&&!y)
		return 0;
	return (a[x]==y+'0'||a[x]=='?');
}
inline bool judge(int id,int x,int y)
{
	return !(x>len[id]&&!y);
}
signed main()
{
	//freopen("digits.in","r",stdin);
	//freopen("digits.out","w",stdout);
	memset(dp,-0x3f,sizeof dp);
	scanf("%s",a+1);
	m=len[0]=strlen(a+1);
	reverse(a+1,a+m+1);
	scanf("%lld",&n);
	for(register int i=1;i<=n;++i)
	{
		scanf("%s",b[i]+1);
		len[i]=strlen(b[i]+1);
		reverse(b[i]+1,b[i]+len[i]+1);
		m=max(m,len[i]);
		len[i]=max(len[i],len[0]);
	}
	for(register int i=0;i<10;++i)
		scanf("%lld",&c[i]);
	int tmp=strlen(a+1);
	for(register int i=tmp+1;i<=m;++i)
		a[i]='0';
	for(register int i=1;i<=n;++i)
	{
		tmp=strlen(b[i]+1);
		for(register int j=tmp+1;j<=m;++j)
			b[i][j]='0';
	}
	dp[0][n+1]=0;
	for(register int i=1;i<=n;++i)
		ord[0][i]=i;
	for(register int i=1;i<=m;++i)
		b[0][i]=15+'0';
	for(register int i=1;i<=m;++i)
	{
		for(register int j=0;j<10;++j)
			t[j].clear();
		for(register int j=1;j<=n;++j)
			t[b[ord[i-1][j]][i]-'0'].push_back(ord[i-1][j]);
		int cnt=0;
		for(register int j=0;j<10;++j)
			for(register int k=0;k<(int)(t[j].size());++k)
				ord[i][++cnt]=t[j][k];
		for(register int j=0;j<10;++j)
		{
			sum[j]=0;
			pos[j]=n+1;
			for(register int k=n;k>=1;--k)
				if(judge(ord[i][k],i,j))
					sum[j]+=c[(b[ord[i][k]][i]-'0'+j)%10];
			while(pos[j]>0&&b[ord[i][pos[j]]][i]-'0'+j>=10)
				--pos[j];
			++pos[j];
			if(check(i,j))
				dp[i][pos[j]]=max(dp[i][pos[j]],dp[i-1][n+1]+sum[j]);
		}
		for(register int j=1;j<=n;++j)
			vis[j]=0;
		vis[0]=114514;
		for(register int j=n;j>=1;--j)
		{
			vis[ord[i-1][j]]=1;
			for(register int k=0;k<10;++k)
			{
				if(judge(ord[i-1][j],i,k))
					sum[k]-=c[(b[ord[i-1][j]][i]-'0'+k)%10];
				sum[k]+=c[(b[ord[i-1][j]][i]-'0'+k+1)%10];
				while(pos[k]>0&&b[ord[i][pos[k]]][i]-'0'+k+vis[ord[i][pos[k]]]>=10)
					--pos[k];
				++pos[k];
				if(check(i,k))
					dp[i][pos[k]]=max(dp[i][pos[k]],dp[i-1][j]+sum[k]);
			}
		}
	}
	ans=dp[m][n+1];
	for(register int i=n;i>=1;--i)
		ans=max(ans,dp[m][i]+(n-i+1)*c[1]);
	printf("%lld\n",ans);
	return 0;
}
//I'm faster than Felipe!