#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define int ll
#define eps 1e-6
#define pb push_back
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(ll x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}


struct fs{ll fz,fm;fs(int _fz=0,int _fm=0){fz=_fz,fm=_fm;}};
struct node{ll x,v;fs t,tt;ll T,TT;}	e[100001];
bool operator <(fs x, fs y)	{return x.fz*y.fm<x.fm*y.fz;}
bool operator ==(fs x,fs y)	{return x.fz*y.fm==x.fm*y.fz;}
int n,w,top,tr[200001];
fs q[200001],tq[200001];
ll ans;
inline bool cmp(node x,node y){return x.T!=y.T?x.T<y.T:x.TT>y.TT;}
inline int Ask(int x){int sum=0;for(;x<=top;x+=x&-x)	sum+=tr[x];return sum;}
inline void Add(int x,int v){for(;x;x-=x&-x)	tr[x]+=v;}
inline int lower(fs x)
{
	int l=1,r=top,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(tq[mid]<x)	ans=mid,l=mid+1;else	r=mid-1;
	}
	return ans+1;
}
main()
{
	// freopen("in.in","r",stdin);
	n=read();w=read();
	For(i,1,n)
	{
		e[i].x=read();e[i].v=read();
		bool rev=0;
		if(e[i].v<0)	e[i].v=-e[i].v,e[i].x=-e[i].x,rev=1;
		e[i].t=fs(-e[i].x,e[i].v+w);e[i].tt=fs(-e[i].x,e[i].v-w);
		if(rev)	swap(e[i].t,e[i].tt);
		q[++top]=e[i].t;q[++top]=e[i].tt;
	}
	sort(q+1,q+top+1);
	int tep=0;
	For(i,1,top)	if(i==1||(!(q[i]==q[i-1])))	tq[++tep]=q[i];
	top=tep;
	For(i,1,n)	e[i].T=lower(e[i].t),e[i].TT=lower(e[i].tt);
	sort(e+1,e+n+1,cmp);
	For(i,1,n)
		ans+=1ll*Ask(e[i].TT),Add(e[i].TT,1);
	writeln(ans);
}