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
int n,m,mn=100,mc=100;
bool ha[10],hb[10];
int main()
{
	cin>>n>>m;
	for(int i=1,x;i<=n;++i)
		re(x),ha[x]=1,mn=min(mn,x);
	for(int i=1,x;i<=m;++i)
		re(x),hb[x]=1,mc=min(mc,x);
	for(int i=1;i<=9;++i)
		if(ha[i] && hb[i])	
		{
			printf("%d\n",i);
			return 0;
		}
	printf("%d\n",min(mn*10+mc,mc*10+mn));
}