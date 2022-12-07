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
char ch;bool fs;void re(LL& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
LL n,m,k,ans,top,last[100005],a[100005];
int main()
{
	re(n),re(k),re(m);
	ans=n*m;
	for(LL i=1;i<=n;++i)
	{
		re(a[++top]);
		if(a[top]==a[top-1])last[top]=last[top-1]+1;
		else last[top]=1;
		if(last[top]==k)
		{
			top-=k;
			ans-=k*m;
		}
	}
	LL l=1,r=top;
	while(1)
	{
		if(a[l]!=a[r])break;
		LL lp=l,rp=r;
		if(l==r)
		{
			if(m%k == 0)
				ans=0;
			else ans-=m-m%k;
			break;
		}
		while(lp<rp-1 && a[lp+1]==a[r])++lp;
		while(lp<rp-1 && a[rp-1]==a[l])--rp;
		LL len=lp-l+r-rp+2;
		if(a[lp]==a[rp] && lp==rp-1)
		{
			if(len*m%k == 0)
				ans=0;
			else ans-=len*m-len*m%k;
			break;
		}
		if(len >= k)
		{
			ans-=(m-1)*k;
			if(len==k)
			{
				l=lp+1,r=rp-1;
			}else break;
		}else break;
	}
	printf("%I64d\n",ans);
}
/*
2 4 3
5 5  
*/