#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v

void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
int n,c,ans;
bool have[111];
int main()
{
	re(n),re(c);
	for(int i=1;i<=n;++i)
	{
		int x;re(x);
		have[x]=1;
	}
	for(int i=0;i<c;++i)
		if(!have[i])
			++ans;
	if(have[c])++ans;
	printf("%d\n",ans);
}