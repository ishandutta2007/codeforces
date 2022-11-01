#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pa pair<int,int>
#define fir first
#define sec second
#define mk make_pair
using namespace std;

inline ll read(){ll x=0,f=1,ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}
inline void write(ll x){if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10); putchar(x%10+'0');}
inline void writeln(ll x){write(x); puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=200005;
int n,xx[N],sz[N],Fa[N],vis[N],cnt,poi[N],nxt[N],head[N],top;
struct node{int x,y,v;}	e[N];
inline bool cmp(node x,node y){return x.v<y.v;}
pa q[N];
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}
inline pa Dfs(int x,int fa)
{
	vis[x]=1;
	pa tmp=mk(1,xx[x]);
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		pa las=Dfs(poi[i],x);
		tmp.fir+=las.fir;tmp.sec+=las.sec;
	}	
	return tmp;
}
inline bool check(int line)
{
	For(i,1,n)	head[i]=0;cnt=0;
	For(i,1,n-1)	if(e[i].v<line)	add(e[i].x,e[i].y);else	break;
	For(i,1,n)	vis[i]=0;
	top=0;
	int sum=0;
	For(i,1,n)	if(!vis[i])	q[++top]=Dfs(i,i),sum+=(q[top].sec);
	pa tmp=mk(0,0);
	For(i,1,n)	if(q[i]>tmp)	tmp=q[i];
	if(tmp.fir>sum-tmp.sec)	return 0;
	else	return 1;
}
int main()
{
	n=read();For(i,1,n-1)	e[i].x=read(),e[i].y=read(),e[i].v=read();
	For(i,1,n)	xx[i]=read();
	sort(e+1,e+n,cmp);
	int l=1,r=1e9,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,l=mid+1;else	r=mid-1;
	}
	writeln(ans);
}