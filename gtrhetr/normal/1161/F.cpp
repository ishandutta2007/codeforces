#include<bits/stdc++.h>
using namespace std;

int a[60][60],b[60][60],c[60][60],to[60],to1[60],t,n;
char s[110];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
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

int id=0;

inline bool cmp(const int &x,const int &y) { return a[id][x]>a[id][y]; }

inline void gao()
{
	static int now[60];
	memset(to,0,sizeof(to));
	memset(to1,0,sizeof(to1));
	memset(now,0,sizeof(now));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) c[i][j]=j;
		id=i;sort(c[i]+1,c[i]+n+1,cmp);
		now[i]=1;
	}
	while (233)
	{
		for (int i=1;i<=n;i++) if (!to[i])
		{
			int x=c[i][now[i]];
			if (!to1[x]||b[x][i]>b[x][to1[x]])
			{
				if (to1[x]) to[to1[x]]=0;
				to[i]=x;to1[x]=i;
			}
			now[i]++;
		}
		bool flag=true;
		for (int i=1;i<=n;i++) if (!to[i]) flag=false;
		if (flag) break;
	}
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=-rd();
		puts("B");fflush(stdout);
		scanf("%s",s+1);
		int x=rd();
		if ((s[1]=='I')^(x<=n)) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]=-a[i][j];
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) b[i][j]=-a[j][i];
		gao();
		while (233)
		{
			print((x<=n)?to[x]+n:to1[x-n]);fflush(stdout);
			x=rd();
			if (x==-1) break;
		}
	}
	return 0;
}