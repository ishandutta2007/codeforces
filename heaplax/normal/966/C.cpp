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
#define int long long
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
vector<int> mx[65];
int n,now,top,st[N];
main()
{
	re(n);
	for(int i=1,x;i<=n;++i)
	{
		re(x);
		int j=0;
		for(int k=x;k;k>>=1)++j;
		mx[j].push_back(x);
	}
	for(int i=1;i<=n;++i)
	{
		bool ok=0;
		for(int j=0;j<=59;++j)	
			if(!(now>>j&1) && mx[j+1].size())
			{
				ok=1;
				st[++top]=mx[j+1].back();
				now^=mx[j+1].back();
				mx[j+1].pop_back();
				break;
			}
		if(!ok)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;++i)
		printf("%lld ",st[i]);
}