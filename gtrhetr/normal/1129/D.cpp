#include<bits/stdc++.h>
using namespace std;
#define mod 998244353

int f[100010],g[100010],sum[410][810],tag[410],st[410],ed[410];
int num[100010],from[100010],lst1[100010],lst2[100010],n,k,sq,block;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }

inline void modify(int x,int y)
{
	int hh=from[x];
	for (int i=1;i<hh;i++) tag[i]+=y;
	for (int i=st[hh];i<=x;i++) g[i]+=y;
	for (int i=0;i<=sq*2;i++) sum[hh][i]=0;
	for (int i=st[hh];i<=ed[hh];i++) sum[hh][g[i]+sq]=pls(sum[hh][g[i]+sq],f[i-1]);
	for (int i=1;i<=sq*2;i++) sum[hh][i]=pls(sum[hh][i],sum[hh][i-1]);
}

inline int query(int x,int y)
{
	int hh=from[x],res=0;
	for (int i=1;i<=hh;i++) if (y-tag[i]>=-sq) res=pls(res,sum[i][min(sq*2,y-tag[i]+sq)]);
	return res;
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	block=0;sq=sqrt(n);
	for (int i=1,j;i<=n;i+=sq)
	{
		st[++block]=i;
		for (j=i;j<=n&&j<i+sq;j++) from[j]=block,ed[block]=j;
	}
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (!lst1[num[i]]) lst1[num[i]]=i,modify(i,1);
		else
		{
			int h1=lst1[num[i]],h2=lst2[num[i]];
			modify(i,1);modify(h2,1);modify(h1,-2);
			lst2[num[i]]=lst1[num[i]];lst1[num[i]]=i;
		}
		f[i]=query(i,k);
	}
	printf("%d\n",f[n]);
	return 0;
}