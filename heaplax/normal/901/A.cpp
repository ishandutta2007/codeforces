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
#define N 100001
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
int n,a[N];
int main()
{
	re(n);
	for(int i=0;i<=n;++i)re(a[i]);
	for(int i=1;i<=n;++i)
		if(a[i-1]>=2 && a[i]>=2)
		{
			puts("ambiguous");
			for(int j=0,last=0,cnt=0;j<=n;++j,last=cnt)
				for(int k=1;k<=a[j];++k)
					{
						printf("%d ",last);
						++cnt;	
					}
			putchar('\n');
			for(int j=0,last=0,cnt=0;j<=n;++j,last=cnt)
				if(j!=i)
				{
					for(int k=1;k<=a[j];++k)
					{
						printf("%d ",last);
						++cnt;	
					}
				}
				else 
				{
					for(int k=1;k<a[j];++k)
					{
						printf("%d ",last);
						++cnt;
					}
					printf("%d ",last-1);
					++cnt;
				}
			return 0;
		}
	puts("perfect");
}