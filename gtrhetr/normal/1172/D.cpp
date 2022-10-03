#include<bits/stdc++.h>
using namespace std;
#define y1 DCXISSOHANDSOME

struct node { int x1,y1,x2,y2; }h[1000010];

int r[1010],c[1010],to1[1010],to2[1010],n,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) r[rd()]=i;
	for (int i=1;i<=n;i++) c[rd()]=i;
	for (int i=1;i<=n;i++) to1[r[i]]=i,to2[c[i]]=i;
	tt=0;
	for (int i=1;i<=n;i++)
	{
		if (r[i]==i&&c[i]==i) continue;
		h[++tt]=(node){i,c[i],r[i],i};
		if (to1[i]>i)
		{
			int h1=r[i],h2=to1[i];
			to1[h1]=h2;r[h2]=h1;
		}
		if (to2[i]>i)
		{
			int h1=c[i],h2=to2[i];
			to2[h1]=h2;c[h2]=h1;
		}
	}
	printf("%d\n",tt);
	for (int i=1;i<=tt;i++) printf("%d %d %d %d\n",h[i].x1,h[i].y1,h[i].x2,h[i].y2);
	return 0;
}