#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,m,k,ans,a[36];
set<int> s;
void dfs(int now,int sum)
{
	if(now>k)
	{
		ans=max(ans,sum);
		s.insert(sum);
		return;
	}
	else 
	{
		dfs(now+1,sum);
		dfs(now+1,(sum+a[now])%m);
	}
}
void pfs(int now,int sum)
{
	if(now>n)
	{
		set<int> :: iterator p=s.upper_bound(m-sum-1);
		--p;
		ans=max(ans,sum+(*p));
		return;
	}
	else 
	{
		pfs(now+1,sum);
		pfs(now+1,(sum+a[now])%m);
	}
}
int main()
{
	re(n),re(m);
	k=n>>1;
	for(int i=1;i<=n;++i)re(a[i]);
	s.insert(0);
	dfs(1,0);
	pfs(k+1,0);
	printf("%d\n",ans);
}