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
int n,a,b,c;
int main()
{
	re(n),re(a),re(b),re(c);
	if(n==1)puts("0");
	else if(a<=b && a<=c)
		printf("%d\n",(n-1)*a);
	else if(b<=a && b<=c)
		printf("%d\n",(n-1)*b);
	else printf("%d\n",min(a,b)+(n-2)*c);
	
}