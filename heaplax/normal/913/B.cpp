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
#define N 1001
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
int n,fa[N],cnt[N];
bool leaf[N];
int main()
{
	re(n);
	for(int i=2;i<=n;++i)
	{
		re(fa[i]);
		leaf[fa[i]]=1;
	}
	for(int i=2;i<=n;++i)
		if(!leaf[i])
		{
			++cnt[fa[i]];
		}
	for(int i=1;i<=n;++i)
		if(leaf[i] && cnt[i]<3)
		{
			puts("No");
			return 0;
		}
	puts("Yes");
}