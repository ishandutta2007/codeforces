#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
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
set<int> l,e;
set<int>::iterator a,b;
int n,m,cl,ce,v,q;
int main()
{
	re(n),re(m),re(cl),re(ce),re(v);
	for(int i=1,x;i<=cl;++i)
	{
		re(x);
		l.insert(x);
	}
	for(int i=1,x;i<=ce;++i)
	{
		re(x);
		e.insert(x);
	}
	re(q);
	for(int x1,y1,x2,y2;q--;)
	{
		re(x1),re(y1),re(x2),re(y2);
		if(y1>y2)swap(x1,x2),swap(y1,y2);
		if(x1==x2)
		{
			printf("%d\n",y2-y1);
			continue;
		}
		int ans=INF;
		
		a=l.lower_bound(y1);
		if(a!=l.end())
			ans=min(ans,max(0,2*(*a-y2))+y2-y1+abs(x1-x2));
		if(a!=l.begin())
			--a,ans=min(ans,y2-y1+2*(y1-*a)+abs(x1-x2));
		
		a=e.lower_bound(y1);
		if(a!=e.end())
			ans=min(ans,max(0,2*(*a-y2))+y2-y1+(abs(x1-x2)-1)/v+1);
		if(a!=e.begin())
			--a,ans=min(ans,y2-y1+2*(y1-*a)+(abs(x1-x2)-1)/v+1);
		
		printf("%d\n",ans);
	}
}