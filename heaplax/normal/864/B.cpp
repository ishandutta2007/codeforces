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
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout); 
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
bool have[333];
int now,mx,n;
char p[333];
int main()
{
	scanf("%d%s",&n,p);
	for(int i=0;i<=n;++i)
	{
		if(!islower(p[i]))
		{
			if(now>mx)mx=now;
			now=0;
			memset(have,0,sizeof have);
		}
		else 
			if(!have[p[i]])have[p[i]]=1,++now;
	}
	printf("%d\n",mx);
}