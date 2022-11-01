#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define int ll
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read()
{
	ll t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

ll n,a,b,sum,use[500001],ans=0;
struct node{ll x,y,v;}	e[500001];
inline bool cmp(node x,node y){return x.v>y.v;}
signed main()
{
	n=read();a=read();b=read();
	For(i,1,n)	e[i].x=read(),e[i].y=read(),e[i].v=e[i].x-e[i].y;
	sort(e+1,e+n+1,cmp);
	For(i,1,b)	sum+=max(e[i].x,e[i].y);
	int t=0;
	For(i,1,b)	if(e[i].x>e[i].y)	use[i]=1,t++;
	
	For(i,b+1,n)	sum+=e[i].y;
	ans=max(ans,sum);
	if(b!=0)
	For(i,1,n)
	{
		ll tmp=e[i].x,tsum=sum;
		For(j,1,a)	tmp*=2;
		if(use[i])	sum-=e[i].v,sum+=tmp-e[i].y;	
		else
		{
			if(t==b)	sum-=e[b].v;
			sum+=tmp-e[i].y;
		}
		ans=max(ans,sum);
		sum=tsum;
	}
	writeln(ans);
}