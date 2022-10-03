#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

pii h[1500010];

int num[300010],pos[300010],n,tt;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void gao(int x,int y)
{
	int h1=num[x],h2=num[y];
	pos[h1]=y;pos[h2]=x;
	h[++tt]=pii(x,y);
	num[x]=h2;num[y]=h1;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) pos[num[i]]=i;
	for (int i=1;i<=n/2;i++)
	{
		if (pos[i]==i) continue;
		if (pos[i]<=n/2)
		{
			int hh=pos[i];
			gao(hh,n);gao(i,n);
		}
		else
		{
			if (i==1) { gao(1,pos[i]);continue; }
			int hh=pos[i];
			if (hh==n) { gao(i,hh);continue; }
			gao(1,hh);gao(1,n);gao(i,n);gao(1,hh);
		}
	}
	for (int i=n/2+1;i<=n;i++)
	{
		if (pos[i]==i) continue;
		int hh=pos[i];
		gao(1,hh);gao(1,i);gao(1,hh);
	}
	printf("%d\n",tt);
	for (int i=1;i<=tt;i++) printf("%d %d\n",h[i].first,h[i].second);
	return 0;
}