#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=210;
int n,num;
LL len;
int a[N],val[N],ch[N][26],g[N];
LL d[N][N],ans[N][N],tmp[N][N];
char s[N];
queue<int> Q;
void mult(LL a[][N],LL b[][N])
{
	for (int i=1;i<=num;i++)
	for (int j=1;j<=num;j++)
		tmp[i][j]=-1;
	for (int k=1;k<=num;k++)
	for (int i=1;i<=num;i++)
	for (int j=1;j<=num;j++)
	if (a[i][j]>=0&&b[j][k]>=0)
		tmp[i][k]=max(tmp[i][k],a[i][j]+b[j][k]);
	for (int i=1;i<=num;i++)
	for (int j=1;j<=num;j++)
		a[i][j]=tmp[i][j];
}
int main()
{
	scanf("%d%lld",&n,&len);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	num=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=strlen(s+1),now=1;
		for (int j=1;j<=m;j++)
		{
			if (ch[now][s[j]-'a']==0) ch[now][s[j]-'a']=++num;
			now=ch[now][s[j]-'a'];
		}
		val[now]+=a[i];
	}
	for (int i=0;i<26;i++) 
	if (ch[1][i]) Q.push(ch[1][i]),g[ch[1][i]]=1;
	g[1]=1;
	while (!Q.empty())
	{
		int now=Q.front();Q.pop();
		for (int c=0;c<26;c++)
		if (ch[now][c])
		{
			int j=ch[now][c],k=g[now];
			while (!ch[k][c]&&k>1) k=g[k];
			if (ch[k][c]) k=ch[k][c];
			g[j]=k;val[j]+=val[k];Q.push(j);
	//		printf("%d %d\n",j,k);
		}
	}
	for (int i=1;i<=num;i++)
	for (int j=1;j<=num;j++)
		d[i][j]=ans[i][j]=-1;
	for (int i=1;i<=num;i++) ans[i][i]=0;
	for (int i=1;i<=num;i++)
	for (int j=0;j<26;j++)
	{
		int k=i;
		while (!ch[k][j]&&k>1) k=g[k];
		if (ch[k][j]) k=ch[k][j];
		d[i][k]=val[k];
	}
	while (len)
	{
		if (len&1) mult(ans,d);
		len>>=1;mult(d,d);
	}
	LL res=0;
	for (int i=1;i<=num;i++) res=max(res,ans[1][i]);
	printf("%lld\n",res);
	return 0;
}