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
int q,n,ans;
int main()
{
	re(q);
	while(q--)
	{
		re(n);
		if(n%4==0 || n%4==2)ans=n/4;
		else if(n%4==1)ans=(n-5)/4;
		else if(n<=11)ans=0;
		else ans=(n-15)/4+2;
		printf("%d\n",ans?ans:-1);
	}
}