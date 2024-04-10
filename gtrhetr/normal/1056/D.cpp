#include<bits/stdc++.h>
using namespace std;

int fa[100010],size[100010],sum[100010],cnt[100010],n;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

int main()
{
	n=rd();
	for (int i=2;i<=n;i++) fa[i]=rd();
	for (int i=n;i;i--)
	{
		size[i]++;
		size[fa[i]]+=size[i];
		if (size[i]==1) sum[i]++;
		sum[fa[i]]+=sum[i];
	}
	for (int i=1;i<=n;i++) cnt[sum[i]]++;
	for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	int now=1;
	for (int i=1;i<=n;i++)
	{
		while (cnt[now]<i) now++;
		print(now);
	}
	putchar('\n');
	return 0;
}