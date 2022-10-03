#include<bits/stdc++.h>
using namespace std;

int id[110],id1[110],cnt[32768],c[32768],n,m,p,ans=0;
bool bo[200010][110],b[110];
char s[110];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

mt19937 rnd(time(NULL));

inline void gao(int *a,int n)
{
	for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++) a[j]+=a[j+(w>>1)];
}

int main()
{
	n=rd();m=rd();p=rd();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) bo[i][j]=s[j]-'0';
	}
	int hh=n/2;
	if (n&1) hh++;
	for (int i=1;i<32768;i++) c[i]=c[i>>1]+(i&1);
	for (int hhh=1;hhh<=30;hhh++)
	{
		int x=rnd()%n+1,tt=0;
		for (int i=1;i<=m;i++) if (bo[x][i]) id1[tt]=i,id[i]=tt++;
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++)
		{
			int now=0;
			for (int j=0;j<tt;j++) if (bo[i][id1[j]]) now|=(1<<j);
			cnt[now]++;
		}
		gao(cnt,1<<tt);
		for (int i=1;i<(1<<tt);i++) if (cnt[i]>=hh&&c[i]>ans)
		{
			ans=c[i];
			memset(b,false,sizeof(b));
			for (int j=0;j<tt;j++) if ((i>>j)&1) b[id1[j]]=true;
		}
	}
	for (int i=1;i<=m;i++) putchar(b[i]+'0');
	putchar('\n');
	return 0;
}