#include<bits/stdc++.h>
using namespace std;

short *sum[610][610];
int st[610][610],ed[610][610],tag[610][610];
int from[200010],block[200010],m[200010],size[200010];
int pre[200010],a[200010],b[200010],c[200010],team[200010],n,k,q,sq,ans,cannot;

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
	if (x<0) putchar('-'),x=-x;
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void build(int x)
{
	int lst=x+k*((n-x)/k);
	if (k>sq)
	{
		for (int i=x;i<=n;i+=k)
		{
			pre[i]=((i>k)?pre[i-k]:0)^c[i];
			if (!pre[i]) ans++;
		}
		if (pre[lst]) cannot++;
		return;
	}
	m[x]=(n-x)/k+1;size[x]=sq;
	for (int i=1,j=x;i<=m[x];i+=size[x],j+=size[x]*k)
	{
		block[x]++;st[x][block[x]]=j;
		for (int K=i,l=j;K<i+size[x]&&K<=m[x];K++,l+=k) from[l]=block[x],ed[x][block[x]]=l;
	}
	for (int j=x;j<=n;j+=k) pre[j]=((j>k)?pre[j-k]:0)^c[j];
	if (pre[lst]) cannot++;
	for (int i=1;i<=block[x];i++)
	{
		sum[x][i]=new short[1<<14];
		memset(sum[x][i],0,sizeof(short)<<14);
	}
	for (int j=x;j<=n;j=ed[x][from[j]]+k)
	{
		for (int l=j;l<=ed[x][from[j]];l+=k) sum[x][from[j]][pre[l]]++;
		ans+=sum[x][from[j]][0];
	}
}

inline void modify(int x,int y)
{
	int lst=x+k*((n-x)/k);
	if (k>sq)
	{
		if (pre[lst]) cannot--;
		for (int i=x;i<=n;i+=k)
		{
			if (!pre[i]) ans--;
			pre[i]=((i>k)?pre[i-k]:0)^c[i];
			if (!pre[i]) ans++;
		}
		if (pre[lst]) cannot++;
		return;
	}
	int hh=(x-1)%k+1;
	if (pre[lst]^tag[hh][from[lst]]) cannot--;
	for (int j=x;j<=ed[hh][from[x]];j+=k) pre[j]^=y;
	for (int j=st[hh][from[x]];j<=ed[hh][from[x]];j+=k) pre[j]^=tag[hh][from[x]];
	ans-=sum[hh][from[x]][tag[hh][from[x]]];
	tag[hh][from[x]]=0;
	memset(sum[hh][from[x]],0,sizeof(short)<<14);
	for (int j=st[hh][from[x]];j<=ed[hh][from[x]];j+=k) sum[hh][from[x]][pre[j]]++;
	ans+=sum[hh][from[x]][0];
	for (int j=from[x]+1;j<=block[hh];j++)
	{
		ans-=sum[hh][j][tag[hh][j]];
		tag[hh][j]^=y;
		ans+=sum[hh][j][tag[hh][j]];
	}
	if (pre[lst]^tag[hh][from[lst]]) cannot++;
}

int main()
{
	n=rd();k=rd();q=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) b[i]=rd();
	n++;
	for (int i=1;i<=n;i++) c[i]=(a[i]^b[i])^(a[i-1]^b[i-1]);
	sq=sqrt(n);
	for (int i=1;i<=n;i++) team[i]=(i-1)%k+1;
	cannot=0;
	for (int i=1;i<=k;i++) build(i);
	print((cannot)?-1:n-ans);
	while (q--)
	{
		char ch=getchar();
		for (;ch!='a'&&ch!='b';ch=getchar());
		int x=rd(),y=rd();
		if (ch=='a') a[x]=y;
		else b[x]=y;
		int lst1=c[x],lst2=c[x+1];
		c[x]=((a[x]^b[x])^(a[x-1]^b[x-1]));
		c[x+1]=((a[x+1]^b[x+1])^(a[x]^b[x]));
		modify(x,c[x]^lst1);modify(x+1,c[x+1]^lst2);
		print((cannot)?-1:n-ans);
	}
	return 0;
}