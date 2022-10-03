#include<bits/stdc++.h>
using namespace std;

int to[20010][15][31];
int a[20010],b[20010],mxd[20010],mx[20010][15],n,m,K;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline int getmax(const int &x,const int &y) { return b[x]>b[y]?x:y; }

inline int calc(const int &l,const int &r)
{
	int d=mxd[r-l+1];
	return getmax(mx[l][d],mx[r-(1<<d)+1][d]);
}

inline void gao(int *f,int x)
{
	for (int i=K;~i;i--) for (int j=K-i;~j;j--) f[i+j]=max(f[i+j],to[f[i]][x][j]);
}

int f[31],g[31];

inline bool check(int *f,int r)
{
	for (int i=0;i<=K;i++) if (f[i]+a[f[i]]+K-i>=r) return true;
	return false;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i]=rd(),b[i]=min(i+a[i],n);
	for (int i=2;i<=n;i++) mxd[i]=mxd[i>>1]+1;
	for (int i=1;i<=n;i++) mx[i][0]=i;
	for (int j=1;j<=14;j++) for (int i=1;i+(1<<j)-1<=n;i++) mx[i][j]=getmax(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	K=30;
	for (int i=n;i;i--)
	{
		for (int j=0;j<=K;j++) to[i][0][j]=calc(i,min(i+a[i]+j,n));
		for (int j=1;j<=14;j++)
		{
			memcpy(to[i][j],to[i][j-1],sizeof(to[i][j]));
			gao(to[i][j],j-1);
		}
	}
	while (m--)
	{
		int l=rd(),r=rd();K=rd();
		if (l==r) { print(0);continue; }
		if (l+a[l]+K>=r) { print(1);continue; }
		for (int i=0;i<=30;i++) f[i]=l;
		int res=0;
		for (int i=14;~i;i--)
		{
			memcpy(g,f,sizeof(g));gao(g,i);
			if (!check(g,r)) { res+=(1<<i);memcpy(f,g,sizeof(f)); }
		}
		print(res+2);
	}
	return 0;
}