#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans=0;
ll s0[200010],s1[200010];
int num[100010],id[200010],n,m,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll gao()
{
	memset(s0,0,sizeof(s0));
	memset(s1,0,sizeof(s1));
	memset(id,0,sizeof(id));
	tt=0;
	for (int i=1;i<=n;i++) id[n-i]=++tt,s0[tt]=1,s1[tt]=i;
	for (int i=1;i<=m;i++)
	{
		int now=(i-1)-(num[i]-1)+n;
		if (!id[now]) continue;
		if (!id[now+1]) id[now+1]=++tt;
		s0[id[now+1]]+=s0[id[now]];
		s1[id[now+1]]+=s1[id[now]];
		id[now]=0;
	}
	ll res=0;
	for (int i=0;i<=n+m+1;i++) if (id[i])
	{
		int hh=m-(i-n);
		hh=min(hh+1,n);
		res+=(ll)s0[id[i]]*(hh+1)-s1[id[i]];
	}
	return res;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++) num[i]=rd();
	if (n==1) { puts("0");return 0; }
	ans+=gao();
	for (int i=1;i<=m;i++) num[i]=n-num[i]+1;
	ans+=gao();
	printf("%lld\n",ans-n);
	return 0;
}