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
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
int n,k,l,dy[300001];
bool use[600001];
long long ans;
struct node
{
	int a,b;
	bool operator < (const node& i)const
	{
		return a==i.a?b>i.b:a>i.a;
	}
}fuck[300001];
int main()
{
	re(n),re(k);
	for(int i=1;i<=k;++i)use[i]=true;l=k+1;
	for(int i=1;i<=n;++i)	
		re(fuck[i].a),ans-=(LL)i*fuck[i].a,fuck[i].b=i;
	sort(fuck+1,fuck+n+1);
	for(int i=1;i<=n;++i)
	{
		if(!use[fuck[i].b])
		{
			use[fuck[i].b]=true;
			ans+=(LL)fuck[i].b*fuck[i].a;
			dy[fuck[i].b]=fuck[i].b;
		}
		else
		{
			while(use[l])++l;
			use[l]=true;
			ans+=(LL)l*fuck[i].a;
			dy[fuck[i].b]=l;
		}
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i)
		printf("%d ",dy[i]);
}