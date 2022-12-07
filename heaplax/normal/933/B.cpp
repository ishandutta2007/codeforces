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
LL f,m;
LL ans[100010];
int main()
{
	scanf("%lld%lld",&f,&m);
	int n = 0;
	while (f)
	{
		if(n % 2 == 1)
		{
			if(f % m == 0) ans[++ n] = 0; 
			else ans[++ n] = m - (f % m);
			f = (f - 1) / m + 1;
		}
		else ans[++ n] = f % m, f = f / m;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
}