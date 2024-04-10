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
#define N 300001
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
struct node
{
	int c,id;
	bool operator < (const node &a)const
	{
		return c<a.c;
	}
}e[N];
int n,x1,x2,c[N];
int main()
{
	re(n),re(x1),re(x2);
	for(int i=1;i<=n;++i)
		re(c[i]),e[i].c=c[i],e[i].id=i;
	sort(e+1,e+n+1);
	sort(c+1,c+n+1);
	for(int i=n;i;--i)
		if(x1 <= c[i]*(n-i+1))
		{
			for(int j=i-1;j;--j)
				if(x2 <= c[j]*(i-j))
				{
					puts("Yes");
					printf("%d %d\n",n-i+1,i-j);
					for(int k=i;k<=n;++k)
						printf("%d ",e[k].id);
					puts("");
					for(int k=j;k<i;++k)
						printf("%d ",e[k].id);
					puts("");
					return 0;
				}
			break;
		}
	for(int i=n;i;--i)
		if(x2 <= c[i]*(n-i+1))
		{
			for(int j=i-1;j;--j)
				if(x1 <= c[j]*(i-j))
				{
					puts("Yes");
					printf("%d %d\n",i-j,n-i+1);
					for(int k=j;k<i;++k)
						printf("%d ",e[k].id);
					puts("");
					for(int k=i;k<=n;++k)
						printf("%d ",e[k].id);
					puts("");
					return 0;
				}
			break;
		}
	puts("No");
}