#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int a[40],q[2000001],ans,top,mo,n;

inline int lower(int x)
{
	int l=1,r=top,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(q[mid]<=x)	ans=mid,l=mid+1;else r=mid-1;
	}
	return ans;
}
inline void Solve(int x)
{
	int t=mo-x-1;
	int p=lower(t);
	ans=max(ans,x+q[p]);
//	cout<<x<<' '<<q[p]<<endl;
	t=2*mo-x-1;
	p=lower(t);
	ans=max(ans,(x+q[p])%mo);
//	cout<<x<<' '<<q[p]<<
}
inline void Dfs1(int x,int now)
{
	if(x==n/2+1)	{q[++top]=now;ans=max(ans,now);return;}
	Dfs1(x+1,(now+a[x])%mo);Dfs1(x+1,now);
}
inline void Dfs2(int x,int now)
{
	if(x==n+1)	{Solve(now);ans=max(ans,now);return;}
	Dfs2(x+1,(now+a[x])%mo);Dfs2(x+1,now);
}
int main()
{
	n=read();mo=read();
	For(i,1,n)
		a[i]=read();
	Dfs1(1,0);
	sort(q+1,q+top+1);
	Dfs2(n/2+1,0);
	cout<<ans<<endl;
}