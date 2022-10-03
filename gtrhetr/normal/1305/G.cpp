#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans=0;
int num[200010],from[300010],size[300010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline void merge(int x,int y,int z)
{
	if (!size[x]||!size[y]) return;
	x=find(x);y=find(y);
	if (x!=y)
	{
		ans+=(ll)z*(size[x]+size[y]-1);
		from[x]=y;size[y]=1;
	}
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=0;i<=262144;i++) from[i]=i;
	for (int i=1;i<=n;i++) size[num[i]]++,ans-=num[i];
	size[262144]=1;
	for (int i=262143;~i;i--)
	{
		for (int j=i;j;j=(j-1)&i) merge(j,i^j,i);
		merge(i,262144,i);
	}
	printf("%lld\n",ans);
	return 0;
}