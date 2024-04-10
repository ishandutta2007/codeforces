#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<list>
#include<queue>
#include<string>
using namespace std;
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define LS k<<1
#define RS k<<1|1
#define ll long long
#define lb long double
#define db double
#define PII pair<int,int>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forn(i,a,b) for(int i=a;i>=b;i--)
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 100010
int dex[N],tot=1;
struct node{
	int ed,before;
}g[N*2];
inline void add(int x,int y){
	g[++tot].ed=y;g[tot].before=dex[x];dex[x]=tot;
}
int n,q;
int size[N];
ll sumdis[N];
#define Z 20
int F[N][Z+5],dep[N];
inline void Find(int u){
	size[u]=1;
	for(int j=dex[u],v;j;j=g[j].before){
		v=g[j].ed;if(v==F[u][0])continue;
		F[v][0]=u;dep[v]=dep[u]+1;Find(v);size[u]+=size[v];
		sumdis[u]+=sumdis[v]+1ll*size[v]; 
	}
}
inline void init(){
	For(i,1,20)For(j,1,n)F[j][i]=F[F[j][i-1]][i-1];
}
inline int Up(int u,int dis){
	Forn(i,20,0)if(dis-(1<<i)>=0)u=F[u][i],dis-=(1<<i);
	return u;
}
inline int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	v=Up(v,dep[v]-dep[u]);
	if(u==v)return u;
	Forn(i,20,0)if(F[u][i]!=F[v][i]&&F[u][i]&&F[v][i]){
		u=F[u][i],v=F[v][i];
	}return F[u][0];
}
ll sumall[N];
inline void Work(int u){
	for(int j=dex[u],v;j;j=g[j].before){
		v=g[j].ed;if(v==F[u][0])continue;
		sumall[v]=sumall[u]-1ll*size[v]+n-size[v];
		Work(v);
	} 
}
int main(){
	n=read();q=read();
	For(i,1,n-1){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}Find(1);sumall[1]=sumdis[1];Work(1);
	init();
	for(;q--;){
		int u=read(),v=read(),x=lca(u,v);
		double ans=dep[u]+dep[v]-dep[x]*2+1;
    	if(x==u){
        	int z=Up(v,dep[v]-dep[u]-1);
        	ans+=1.0*(sumall[u]-sumdis[z]-size[z])/(n-size[z]);
    	}else ans+=1.0*sumdis[u]/size[u];
   		if(x==v){
        	int z=Up(u,dep[u]-dep[v]-1);
        	ans+=1.0*(sumall[v]-sumdis[z]-size[z])/(n-size[z]);
    	}else ans+=1.0*sumdis[v]/size[v];
    	printf("%.12lf\n",ans);
	}
}