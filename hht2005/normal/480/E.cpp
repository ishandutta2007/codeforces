#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int maxn=2010;
char mp[maxn][maxn];
int a[maxn][maxn],x[maxn],y[maxn],ans[maxn],n,m,Q;
int f[maxn][maxn],U[maxn][maxn],D[maxn][maxn];
int q[maxn],t[maxn],q1,q2;
int updata(int sum,int x,int y)
{
	q1=1,q2=0;
	for(int i=1;i<=m;i++)
	{
		while(q1<=q2&&q[q1]<=i-sum)q1++;
		while(q1<=q2&&U[x][q[q2]]>U[x][i])q2--;
		q[++q2]=i;
		t[i]=U[x][q[q1]];
	}
	q1=1,q2=0;
	for(int i=1;i<=m;i++)
	{
		while(q1<=q2&&q[q1]<=i-sum)q1++;
		while(q1<=q2&&D[x][q[q2]]>D[x][i])q2--;
		q[++q2]=i;
		t[i]+=D[x][q[q1]]-1;
	}
	for(int i=sum;i<=m;i++)
		if(t[i]>=sum)
			return 1;
	return 0;
}
int main()
{
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++)
			a[i][j]=mp[i][j]=='.'?0:1;
	}
	for(int i=1;i<=Q;i++)
	{
		x[i]=read(),y[i]=read();
		a[x[i]][y[i]]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j])
			{
				U[i][j]=U[i-1][j]+1;
				f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
				sum=max(sum,f[i][j]);
			}
	for(int i=n;i;i--)
		for(int j=m;j;j--)
			if(!a[i][j])
				D[i][j]=D[i+1][j]+1;
	for(int i=Q;i;i--)
	{
		ans[i]=sum;
		a[x[i]][y[i]]--;
		if(a[x[i]][y[i]])continue;
		for(int j=x[i];j<=n&&!a[j][y[i]];j++)
			U[j][y[i]]+=U[x[i]-1][y[i]]+1;
		for(int j=x[i];j>=1&&!a[j][y[i]];j--)
			D[j][y[i]]+=D[x[i]+1][y[i]]+1;
		while(updata(sum+1,x[i],y[i]))sum++;
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}