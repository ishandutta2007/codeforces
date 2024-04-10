#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

int fa[400010],size[400010],num[400010],q,tt,ans;

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

inline int find(int x) { return (x==fa[x])?x:find(fa[x]); }

int main()
{
	q=rd();ans=0;
	for (int i=1;i<=400000;i++) fa[i]=i,size[i]=1;
	mp[-1]=++tt;
	while (q--)
	{
		int p=rd(),l=rd()^ans,r=rd()^ans;
		if (l>r) swap(l,r);l--;
		if (p==1)
		{
			int x=rd()^ans;
			if (!mp.count(l)) mp[l]=++tt;
			if (!mp.count(r)) mp[r]=++tt;
			l=mp[l];r=mp[r];
			int f1=find(l),f2=find(r);
			if (f1==f2) continue;
			int h1=0,h2=0;
			for (int i=l;i!=f1;i=fa[i]) h1^=num[i];
			for (int i=r;i!=f2;i=fa[i]) h2^=num[i];
			if (size[f1]<size[f2])
			{
				fa[f1]=f2;size[f2]+=size[f1];
				num[f1]=h1^h2^x;
			}
			else
			{
				fa[f2]=f1;size[f1]+=size[f2];
				num[f2]=h1^h2^x;
			}
		}
		else
		{
			if (!mp.count(l)||!mp.count(r)) { print(-1);ans=1;continue; }
			l=mp[l];r=mp[r];
			int f1=find(l),f2=find(r);
			if (f1!=f2) { print(-1);ans=1;continue; }
			int h1=0,h2=0;
			for (int i=l;i!=f1;i=fa[i]) h1^=num[i];
			for (int i=r;i!=f2;i=fa[i]) h2^=num[i];
			print(ans=(h1^h2));
		}
	}
	return 0;
}