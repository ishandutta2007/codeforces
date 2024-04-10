//by yjz
#include<bits/stdc++.h>
using namespace std;
#define PB push_back 
typedef long long ll;
const int Imx=2147483647;
char s[1011],ss[1011];
int id[1011],a[1011][1011],sz[1011];
int n,m,w[12],nw[1011],cw[1011];
int dp[1011],ndp[1011],pos[12],cnt[12],it[12];
vector<int>v[10];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	reverse(s,s+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",ss);
		sz[i]=strlen(ss);
		reverse(ss,ss+sz[i]);
		for(int j=0;j<sz[i];j++)a[i][j]=ss[j]-'0';
	}
	for(int i=0;i<10;i++)scanf("%d",&w[i]);
	for(int i=0;i<m;i++)
	{
		for(int j=n;j<sz[i];j++)nw[i]+=w[a[i][j]];
		a[i][n]++;sz[i]=max(sz[i],n+1);
		for(int j=n;a[i][j]>=10;j++)a[i][j]=0,a[i][j+1]++;
		if(a[i][sz[i]])sz[i]++;
		for(int j=n;j<sz[i];j++)cw[i]+=w[a[i][j]];
	}
	for(int i=0;i<=m;i++)id[i]=i;
	for(int i=1;i<=m;i++)dp[i]=-1;
	for(int i=0;i<n;i++)
	{
		memset(ndp,-1,sizeof(ndp));
		for(int i=0;i<10;i++)v[i].clear(),it[i]=0,cnt[i]=0;
		for(int j=0;j<m;j++)
		{
			v[a[id[j]][i]].PB(id[j]);
			cnt[a[j][i]]++;
		}
		for(int i=8;i>=0;i--)pos[i]=pos[i+1]+v[i+1].size();
		for(int t=0;t<=m;t++)
		{
			int j=id[t];
			if(dp[t]>=0)
			{
				int mn=Imx;
				for(int v=0;v<10;v++)
				{
					if(s[i]!='?'&&s[i]!='0'+v||i==n-1&&v==0)continue;
					int cur=dp[t];
					for(int k=0;k<10;k++)cur+=cnt[k]*w[(k+v)%10];
					int nxt=pos[9-v]+it[9-v];
					ndp[nxt]=max(ndp[nxt],cur);
				}
			}
			cnt[a[j][i]]--;
			cnt[(a[j][i]+1)%10]++;
			it[a[j][i]]++;
		}
		swap(dp,ndp);
		for(int j=9;j>=0;j--)for(int t=0;t<v[j].size();t++)id[pos[j]+t]=v[j][t];
	}
	int sum=0,ans=0;
	for(int i=0;i<m;i++)sum+=nw[i];
	for(int i=0;i<=m;i++)
	{
		if(dp[i]!=-1)ans=max(ans,dp[i]+sum);
		sum+=cw[id[i]]-nw[id[i]];
	}
	cout<<ans<<endl;
	return 0;
}