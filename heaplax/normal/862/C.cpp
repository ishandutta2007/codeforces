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
int n,x,ans,a;
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	re(n),re(x);
	if(n==2 && x==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n==1)
	{
		printf("%d\n",x);
		return 0;
	}
	if(n==2)
	{
		printf("0 %d\n",x);
		return 0;
	}
	for(int i=1;i<=n-3;++i)	
	{
		printf("%d ",i);
		ans^=i;
	}
	ans^=n-2;
	int q=max(ans,x);
	for(int i=0;(1<<i)<=q;++i)
		if((x&(1<<i))^(ans&(1<<i)))	
			a+=1<<i;
	if(a)
		printf("%d 262144 %d\n",n-2,262144+a);
	else 
		printf("%d 0 %d\n",n-2+262144,262144);
}