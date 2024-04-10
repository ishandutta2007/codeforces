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
using namespace std;
void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
int n,a,b,p;
int main()
{
	re(n);
	printf("? ");
	for(int i=1;i<=n;++i)putchar('1');
	puts("");
	fflush(stdout);
	re(a);
	printf("? ");
	putchar('0');for(int i=2;i<=n;++i)putchar('1');
	puts("");
	fflush(stdout);
	re(b);
	if(a<b)p=0;
	else
	{
		printf("? ");
		for(int i=1;i<=n;++i)putchar('0');
		puts("");
		fflush(stdout);
		re(a);
	  	p=1;
	}
	int l=2,r=n;
	while(l < r)
	{
		int mid=l+r>>1;
		printf("? ");
		for(int i=1;i<l;++i)printf("%d",p^1);
		for(int i=l;i<=mid;++i)printf("%d",p);
		for(int i=mid+1;i<=n;++i)printf("%d",p^1);
		puts("");
		fflush(stdout);
		re(b);
		if(b-mid+l<a)r=mid;
		else l=mid+1;
	}
	if(p)printf("! 1 %d\n",l);
	else printf("! %d 1\n",l);
	fflush(stdout);
}
/*
1010100010
1000001111
*/