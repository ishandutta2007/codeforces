#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { ll val,num; }a[300010];

int cnt[300010],n;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool check(int x,int y)
{
	if (!((1LL<<y)&a[x].num)) return false;
	for (int i=0;i<y;i++) if ((1LL<<i)&a[x].num) return false;
	return true;
}

inline int Cnt(int x)
{
	int res=0;
	for (int i=0;i<=61;i++) if ((1LL<<i)&x) res++;
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].val=rd(),a[i].num=rd();
	ll sum=0;
	for (int i=1;i<=n;i++) sum+=a[i].val;
	for (int i=1;i<=n;i++) cnt[i]=Cnt(a[i].num);
	ll s=0;
	for (int i=61;~i;i--)
	{
		ll now=0;
		for (int j=1;j<=n;j++) if (check(j,i)) now+=a[j].val;
		if ((sum<0&&now>=0)||(sum>0&&now<=0)) continue;
		s|=(1LL<<i);
		for (int j=1;j<=n;j++) if ((1LL<<i)&a[j].num) a[j].val=-a[j].val;
	}
	printf("%lld\n",s);
	return 0;
}