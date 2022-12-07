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
#define N 1<<19
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
int n,m,s[N],e[10];
int l[N],r[N],tag[N][10];
LL tmp[10],sum[N][10];
void upd(int k)
{
	for(int i=0;i<=9;++i)
		sum[k][i]=sum[k<<1][i]+sum[k<<1|1][i];
}
void push(int k)
{
	for(int i=0;i<=9;++i)
	{
		tmp[tag[k][i]]+=sum[k][i];
		tag[k<<1][i]=tag[k][tag[k<<1][i]];
		tag[k<<1|1][i]=tag[k][tag[k<<1|1][i]];
	}
	for(int i=0;i<=9;++i)
	{
		sum[k][i]=tmp[i];
		tmp[i]=0;
	}
	memcpy(tag[k],e,sizeof e);
}
void build(int k,int a,int b)
{
	memcpy(tag[k],e,sizeof e);
	l[k]=a,r[k]=b;
	if(a==b)
	{
		for(int t=1;s[a];s[a]/=10,t*=10)
			sum[k][s[a]%10]+=t;
		return;
	}
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
	upd(k);
}
void change(int k,int a,int b,int x,int y)
{
	if(a>r[k] || b<l[k])return;
	if(a<=l[k] && b>=r[k])
	{
		for(int i=0;i<=9;++i)
			if(tag[k][i]==x)
				tag[k][i]=y;
		push(k);
		return;
	}
	push(k);
	push(k<<1);
	push(k<<1|1);
	change(k<<1,a,b,x,y);
	change(k<<1|1,a,b,x,y);
	upd(k);
}
LL ask(int k,int a,int b)
{
	if(a>r[k] || b<l[k])return 0;
	push(k);
	if(a<=l[k] && b>=r[k])
	{
		LL res=0;
		for(int i=0;i<=9;++i)
			res+=sum[k][i]*i;
		return res;
	}
	return ask(k<<1,a,b)+ask(k<<1|1,a,b);
}
int main()
{
	re(n),re(m);
	for(int i=0;i<=9;++i)e[i]=i;
	for(int i=1;i<=n;++i)re(s[i]);
	build(1,1,n);
	for(int opt,a,b,x,y;m--;)
	{
		re(opt),re(a),re(b);
		if(opt==1)
		{
			re(x),re(y);
			change(1,a,b,x,y);
		}
		else printf("%I64d\n",ask(1,a,b));
	}
}