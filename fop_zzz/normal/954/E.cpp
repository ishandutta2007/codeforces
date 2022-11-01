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
#define eps 1e-6
#define int ll
#define pb push_back
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int n,t,tans,tmp;
long double ans;
struct node{int tot,v;}	q[220001];
inline bool cmp(node x,node y){return x.v<y.v;}
main()
{
	n=read();t=read();
	For(i,1,n)	q[i].tot=read(),tans+=q[i].tot;
	For(i,1,n)	q[i].v=read()-t,tmp+=q[i].v*q[i].tot;
	sort(q+1,q+n+1,cmp);
	int mi=1,mx=n;
	while(mi<=mx)
	{
		if(tmp>0)
		{
			if(q[mx].v<=0)	break;
			if(q[mx].v*q[mx].tot>=tmp)	{ans=1.0*tmp/q[mx].v;break;}
			else	tmp-=q[mx].v*q[mx].tot,tans-=q[mx].tot,mx--;
		}
		else
		{
			if(q[mi].v>=0)	break;
			if(-q[mi].v*q[mi].tot>=-tmp)	{ans=1.0*tmp/q[mi].v;break;}
			else	tmp-=q[mi].v*q[mi].tot,tans-=q[mi].tot,mi++;
		}
	}
	printf("%.20lf",tans-(double)ans);
}