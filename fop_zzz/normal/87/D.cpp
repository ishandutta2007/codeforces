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

const int N=100005;
int n,Fa[N],Father[N],poi[N*2],nxt[N*2],head[N],cnt,ans_tot,q[N],dep[N],jy[N];
ll siz[N],ans;
struct node{int x,y,z,p;}	e[N];
inline bool cmp(node x,node y){return x.z!=y.z?x.z<y.z:min(dep[x.x],dep[x.y])>min(dep[y.x],dep[y.y]);}
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline int Get(int x)	{return x==Fa[x]?Fa[x]:Fa[x]=Get(Fa[x]);}
inline void Merge(int x,int y)
{
	if(Father[x]!=y)	swap(x,y);
	int ty=Get(y);
	Fa[x]=ty;
	siz[ty]+=siz[x];jy[x]=siz[x];
}
inline void Solve(int x,int y,int to)
{
	if(Father[x]!=y)	swap(x,y);
	ll tmp=jy[x]*(siz[Get(y)]-jy[x]);
	if(tmp>ans)	ans=tmp,ans_tot=1,q[ans_tot]=to;
	else	if(tmp==ans)	q[++ans_tot]=to;
}
inline void Dfs(int x,int fa)
{
	Father[x]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(fa==poi[i])	continue;
		dep[poi[i]]=dep[x]+1;
		Dfs(poi[i],x);
	}
}
int main()
{
	n=read();
	For(i,1,n)	Fa[i]=i,siz[i]=1;
	For(i,1,n-1)
	{
		e[i].x=read(),e[i].y=read(),e[i].z=read();
		e[i].p=i;
		add(e[i].x,e[i].y);add(e[i].y,e[i].x);
	}
	Dfs(1,1);
	sort(e+1,e+n,cmp);
	int tep=1;
	while(1)
	{
		if(tep>=n)	break;
		int tv=e[tep].z,las=tep;
		while(tep<n&&e[tep].z==tv)	Merge(e[tep].x,e[tep].y),tep++;
		For(i,las,tep-1)	Solve(e[i].x,e[i].y,e[i].p);
	}
	write_p(ans*2ll);writeln(ans_tot);
	sort(q+1,q+ans_tot+1);
	For(i,1,ans_tot)	write_p(q[i]);
}
/*
5
5 4 58958
2 1 37970
2 5 37970
1 3 37970
*/