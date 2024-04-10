#include<bits/stdc++.h>
using namespace std;

int f[310],mx[310][310],g[310][310],mx1[110][310],mx2[110];
int L[110],M[110],R[110],a[110],l[110],h[310],n,tt;

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
	for (int i=1;i<=n;i++) a[i]=rd(),l[i]=rd();
	tt=0;
	for (int i=1;i<=n;i++) h[++tt]=a[i]-l[i],h[++tt]=a[i],h[++tt]=a[i]+l[i];
	sort(h+1,h+tt+1);
	tt=unique(h+1,h+tt+1)-h-1;
	for (int i=1;i<=tt;i++) for (int j=i;j<=tt;j++) mx[i][j]=j;
	for (int i=1;i<=n;i++)
	{
		L[i]=lower_bound(h+1,h+tt+1,a[i]-l[i])-h;
		M[i]=lower_bound(h+1,h+tt+1,a[i])-h;
		R[i]=lower_bound(h+1,h+tt+1,a[i]+l[i])-h;
		mx[M[i]][M[i]]=R[i];
	}
	for (int len=1;len<tt;len++) for (int i=1;i+len<=tt;i++) mx[i][i+len]=max(mx[i][i+len],max(mx[i][i+len-1],mx[i+1][i+len]));
	for (int i=tt;i;i--) for (int j=tt;j>=i;j--)
	{
		if (mx[i][j]<=j) g[i][j]=j;
		else g[i][j]=g[i][mx[i][j]];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=L[i];j<=M[i];j++)
		{
			mx1[i][j]=M[i];
			if (mx[j][M[i]-1]>M[i]) mx1[i][j]=g[M[i]+1][mx[j][M[i]-1]];
		}
		mx2[i]=R[i];
		while (233)
		{
			int hh=mx[M[i]][mx2[i]];
			if (mx2[i]==hh) break;
			mx2[i]=hh;
		}
	}
	for (int i=1;i<=tt;i++)
	{
		f[i]=max(f[i],f[i-1]);
		for (int j=1;j<=n;j++)
		{
			if (M[j]>=i&&L[j]<i) f[mx1[j][i]]=max(f[mx1[j][i]],f[i-1]+h[mx1[j][i]]-h[i-1]);
			if (L[j]==i) f[mx1[j][i]]=max(f[mx1[j][i]],f[i-1]+h[mx1[j][i]]-h[i]);
			if (M[j]==i) f[mx2[j]]=max(f[mx2[j]],f[i-1]+h[mx2[j]]-h[i]);
		}
	}
	printf("%d\n",f[tt]);
	return 0;
}