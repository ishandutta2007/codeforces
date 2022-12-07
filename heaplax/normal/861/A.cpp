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

void re(LL& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
LL n,k,ans;
int main()
{
	re(n),re(k);
	ans=n;
	while(1)
	{
		while(n%10 == 0)
			n/=10,--k;
		if(k<=0)break;
		if(n%2 == 0)
			n*=5,ans*=5;
		else if(n%5 == 0)n*=2,ans*=2;
		else n*=10,ans*=10;
	}
	printf("%I64d\n",ans);
}