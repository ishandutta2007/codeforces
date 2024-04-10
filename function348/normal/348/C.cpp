#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100010,B=410;
int n,m,q,cnt;
LL a[N];
vector<int> b[N];int len[N],id[N];
int c[B];
LL tag[B],ans[B];
int tmp[N];
int d[N][B];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&len[i]);
		b[i].resize(len[i]);
		for (int j=0;j<len[i];j++) scanf("%d",&b[i][j]);
		if (len[i]>300) c[++cnt]=i,id[i]=cnt;
	}
	for (int i=1;i<=cnt;i++)
	{
		for (int j=1;j<=n;j++) tmp[j]=0;
		for (int j=0;j<len[c[i]];j++) 
		{
			tmp[b[c[i]][j]]++;
			ans[i]+=a[b[c[i]][j]];
		}
		tag[i]=0;
		for (int j=1;j<=m;j++) 
		for (int k=0;k<len[j];k++)
			d[j][i]+=tmp[b[j][k]];
	}
	while (q--)
	{
		char ch;
		while ((ch=getchar())<=32);
		if (ch=='+')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (len[x]<=300)
			{
				for (int i=0;i<len[x];i++) a[b[x][i]]+=y;
				for (int i=1;i<=cnt;i++) ans[i]+=1LL*d[x][i]*y;
			}
			else
			{
				tag[id[x]]+=y;

			}
		}
		if (ch=='?')
		{
			int x;
			scanf("%d",&x);
			LL res=0;
			if (len[x]<=300)
			{
				for (int i=0;i<len[x];i++) res+=a[b[x][i]];
				for (int i=1;i<=cnt;i++) res+=1LL*d[x][i]*tag[i];
			}
			else
			{
				res=ans[id[x]];
				for (int i=1;i<=cnt;i++) res+=1LL*d[x][i]*tag[i];
			}
			printf("%I64d\n",res);
		}
	}
	return 0;
}