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
int k,d,t,ans;
main()
{
	re(k),re(d),re(t);t*=2;
	if(k>d)
	{
		if(k%d==0)d=k;
		else d=(k/d+1)*d;
	}
	int x=d+k;
	ans+=(t/x)*d;
	t%=x;
	if(t<=k+k)
	{
		ans+=t/2;
		printf("%I64d",ans);
		if(t&1)printf(".5");
	}
	else 
	{
		ans+=d-(x-t);
		printf("%I64d",ans);
	}
}