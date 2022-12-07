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
#define N 100001
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
int n,m,top,st[N],d[N];
int cnt,head[N],nxt[N],to[N];
bool ok=1,sma[N],big[N];
vector<int> last,now;
int main()
{
	re(n),re(m);
	for(int i=1,c;i<=n;++i)
	{
		re(c);
		for(int x;c--;)
		{
			re(x);
			now.push_back(x);
		}
		if(i!=1)
		{
			int len=min(last.size(),now.size());
			bool ss=0;
			for(int j=0;j<len;++j)	
			{
				if(last[j]<now[j])
				{
					ss=1;
					++d[last[j]];
					add_edge(now[j],last[j]);
					break;
				}
				if(last[j]>now[j])
				{
					if(sma[last[j]])ok=0;
					if(big[now[j]])ok=0;
					ss=big[last[j]]=sma[now[j]]=1;
					break;
				}
			}
			if(!ss && last.size()>now.size())ok=0;	
		}
		last=now;
		now.clear();
	}
	for(int i=1;i<=m;++i)
		if(big[i])
			st[++top]=i;
	while(top)
	{
		int u=st[top--];
		for(int i=head[u],v;i;i=nxt[i])
			if(sma[v=to[i]])
				ok=0;
			else if(!big[v])
				big[v]=1,st[++top]=v;
	}
	if(ok)
	{
		puts("Yes");
		int e=0;
		for(int i=1;i<=m;++i)
			if(big[i])
				++e;
		printf("%d\n",e);
		for(int i=1;i<=m;++i)
			if(big[i])
				printf("%d ",i);
	}else puts("No");
}