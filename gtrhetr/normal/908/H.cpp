#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-(x)))

int f[8388608],g[8388608],cnt[8388608];
int fa[50],from[50],size[50],n,tt;
bool bo[50][50];
char s[50][50];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline void fwt(int *a,int n) { for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++) a[j+(w>>1)]+=a[j]; }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (s[i][j]=='A') fa[find(i)]=find(j);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (find(i)==find(j)&&s[i][j]=='X') { puts("-1");return 0; }
	tt=0;
	for (int i=1;i<=n;i++) if (find(i)==i)
	{
		int now=0;
		for (int j=1;j<=n;j++) if (find(j)==i) now++;
		if (now==1) continue;
		size[++tt]=now;
		for (int j=1;j<=n;j++) if (find(j)==i) from[j]=tt;
	}
	if (tt==0) { printf("%d\n",n-1);return 0; }
	memset(bo,true,sizeof(bo));
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (s[i][j]=='X') bo[from[i]][from[j]]=bo[from[j]][from[i]]=false;
	for (int i=1;i<(1<<tt);i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int i=1;i<=tt;i++) f[1<<(i-1)]=1;
	for (int i=1;i<(1<<tt);i++)
	{
		if (cnt[i]==1||!f[i^lowbit(i)]) continue;
		int id=0;
		for (int j=1;j<=tt;j++) if ((1<<(j-1))&i) { id=j;break; }
		bool flag=true;
		for (int j=1;j<=tt;j++) if (j!=id&&((1<<(j-1))&i)&&!bo[id][j]) { flag=false;break; }
		f[i]=flag;
	}
	fwt(f,1<<tt);
	for (int i=0;i<(1<<tt);i++) g[i]=1;
	for (int i=1;i<=tt;i++)
	{
		for (int j=0;j<(1<<tt);j++) g[j]=g[j]*f[j];
		int now=0;
		for (int j=0;j<(1<<tt);j++) if (cnt[((1<<tt)-1)^j]&1) now-=g[j];else now+=g[j];
		if (now) { printf("%d\n",n-1+i);return 0; }
	}
	puts("-1");
	return 0;
}