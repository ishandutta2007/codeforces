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
#define N 100001
#define M 10000001
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
int n,m,t[N];
set<int> e[N];
set<int>::iterator p;
namespace SEG
{
	int siz,root[N];
	int ls[M],rs[M];
	LL sum[M];
	void modify(int &x,int l,int r,int a,int b)
	{
		if(!x)x=++siz;
		sum[x]+=b;
		if(l==r)return;
		int m=(l+r)>>1;
		if(a<=m)modify(ls[x],l,m,a,b);
		else modify(rs[x],m+1,r,a,b);
	}
	LL query(int x,int l,int r,int a,int b)
	{
		if(!x)return 0;
		if(a<=l && b>=r)return sum[x];
		int m=(l+r)>>1;
		if(b<=m)return query(ls[x],l,m,a,b);
		else if(a>m)return query(rs[x],m+1,r,a,b);
		else return query(ls[x],l,m,a,b)+query(rs[x],m+1,r,a,b);
	}
} 
namespace BIT
{
	using namespace SEG;
	int s[N];
	void add(int x,int y,int z)
	{
		if(!x || x>n || !y || y>n)return;
		for(;x<=n;x+=x&-x)
			modify(root[x],1,n,y,z);
	}
	LL ask(int x,int y,int z)
	{
		LL res=0;
		for(;x;x-=x&-x)	
			res+=query(root[x],1,n,y,z);
		return res;
	}
	LL query(int x,int y,int l,int r)
	{
		return ask(y,l,r)-ask(x-1,l,r);
	}
}
int main()
{
	using namespace BIT;
	re(n),re(m);
	for(int i=1;i<=n;++i)
		e[i].insert(0),e[i].insert(n+1);
	for(int i=1;i<=n;++i)
	{
		re(t[i]);
		e[t[i]].insert(i);
		p=e[t[i]].find(i);
		add(i,*prev(p),i-*prev(p));
	}
	for(int opt,a,b;m--;)
	{
		re(opt),re(a),re(b);
		if(opt==1)
		{
			p=e[t[a]].find(a);
			add(a,*prev(p),*prev(p)-a);
			add(*next(p),a,a-*next(p));
			add(*next(p),*prev(p),*next(p)-*prev(p));
			e[t[a]].erase(p);
			
			t[a]=b;
			e[t[a]].insert(a);
			p=e[t[a]].find(a);
			add(a,*prev(p),a-*prev(p));
			add(*next(p),a,*next(p)-a);
			add(*next(p),*prev(p),*prev(p)-*next(p));
		}
		else printf("%I64d\n",query(a,b,a,b));
	}
}