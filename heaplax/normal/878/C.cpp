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
int n,k;
struct node
{
	int siz,l[11],r[11];
	bool operator < (const node &a)const
	{
		for(int i=1;i<=k;++i)
			if(r[i]>=a.l[i])return 0;
		return 1;
	}
	void merge(const node &a)
	{
		siz+=a.siz;
		for(int i=1;i<=k;++i)
			l[i]=min(l[i],a.l[i]),
			r[i]=max(r[i],a.r[i]);
	}
};
set<node> s;
int main()
{
	re(n),re(k);
	for(int i=1;i<=n;++i)
	{
		node t;t.siz=1;
		for(int j=1;j<=k;++j)
			re(t.l[j]),t.r[j]=t.l[j];
		set<node>::iterator x=s.lower_bound(t),y=s.upper_bound(t);
		while(x!=y)
		{
			t.merge(*x);
			s.erase(*x++);
		}
		s.insert(t);
		printf("%d\n",s.rbegin()->siz);
	}
}