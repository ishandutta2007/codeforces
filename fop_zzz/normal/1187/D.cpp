#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
 
 
using namespace std;
 
inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/
const int N=3e5+5;
int n,a[N],b[N],cnta[N],cntb[N],tr1[N],tr2[N];
struct node{int v,p;}	t[N],tt[N];
inline bool cmp(node x,node y){return x.v!=y.v?x.v<y.v:x.p<y.p;}
inline void Add1(int x,int v){for(;x<=n;x+=x&-x)	tr1[x]=max(tr1[x],v);;}
inline int Ask1(int x){int sum=0;for(;x;x-=x&-x)	sum=max(sum,tr1[x]);return sum;}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		For(i,1,n)	a[i]=read();
		For(i,1,n)	b[i]=read();
		For(i,1,n)	cnta[i]=cntb[i]=0;
		For(i,1,n)	cnta[a[i]]++;
		For(i,1,n)	cntb[b[i]]++;
		bool flag=0;
		For(i,1,n)	if(cnta[i]!=cntb[i])	{puts("NO");flag=1;break;}
		if(flag)	continue;
		For(i,1,n)	t[i].v=a[i],t[i].p=i;
		sort(t+1,t+n+1,cmp);
		For(i,1,n)	tt[i].v=b[i],tt[i].p=i;
		sort(tt+1,tt+n+1,cmp);
		For(i,1,n)	tr1[i]=tr2[i]=0;
		For(i,1,n)	a[t[i].p]=i,b[t[i].p]=tt[i].p;
		For(i,1,n)
		{
			int x=b[i],y=Ask1(a[i]);
			if(x<y)	{puts("NO");flag=1;break;}
			Add1(a[i],b[i]);
		}
		if(!flag)	puts("YES");
	}
}