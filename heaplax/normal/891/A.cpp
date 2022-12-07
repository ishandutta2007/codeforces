#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
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
int n,cnt,mn=100000,a[2001]; 
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
	{
		re(a[i]);
		if(a[i]==1)++cnt;
	}
	if(cnt)
	{
		printf("%d\n",n-cnt);
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1,now=a[i];j<=n;++j)
		{
			now=gcd(now,a[j]);
			if(now==1)mn=min(mn,j-i);
		}
	if(mn==100000)puts("-1");
	else printf("%d\n",n+mn-1);
}