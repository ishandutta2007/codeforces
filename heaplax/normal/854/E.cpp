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
#define N 200001
#define M 7200000
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char che;void re(int& x)
{
	while(che=getchar(),che<33);x=che-48;
	while(che=getchar(),che>33)x=x*10+che-48;
}
using namespace std;
int n,m;
int siz,root[N],ls[M],rs[M],sum[M];
void build(int &x,int y,int l,int r,int a)
{
	x=++siz;
	ls[x]=ls[y];
	rs[x]=rs[y];
	sum[x]=sum[y]+1;
	if(l==r)return;
	int mid=l+r>>1;
	if(a<=mid)build(ls[x],ls[y],l,mid,a);
	else build(rs[x],rs[y],mid+1,r,a);
}
int ask(int x,int l,int r,int a,int b)
{
	if(!x)return 0;
	if(a<=l && b>=r)return sum[x];
	int mid=l+r>>1;
	if(b<=mid)return ask(ls[x],l,mid,a,b);
	else if(a>mid)return ask(rs[x],mid+1,r,a,b);
	else return ask(ls[x],l,mid,a,b)+ask(rs[x],mid+1,r,a,b);
}
bool ch(int x)
{
	return !(x>=1 && x<=n);
}
LL sqr(int x)
{
	return x*(x-1ll);
}
int get(int a,int b,int c,int d)
{
	if(ch(a) || ch(b) || ch(c) || ch(d))return 0;
	else return ask(root[c],1,n,b,d)-ask(root[a-1],1,n,b,d);
}
int main()
{
	re(n),re(m);
	for(int i=1,x;i<=n;++i)
	{
		re(x);
		build(root[i],root[i-1],1,n,x);
	}
	for(int a,b,c,d;m--;)
	{
		re(a),re(b),re(c),re(d);
		LL ans=sqr(n);
		ans-=sqr(a-1);
		ans-=sqr(n-c);
		ans-=sqr(get(1,d+1,n,n));
		ans-=sqr(get(1,1,n,b-1));
		ans+=sqr(get(1,d+1,a-1,n));
		ans+=sqr(get(1,1,a-1,b-1));
		ans+=sqr(get(c+1,d+1,n,n));
		ans+=sqr(get(c+1,1,n,b-1));
		printf("%I64d\n",ans>>1);
	}
}