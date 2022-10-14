#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
const int N=1e5+1,M=400,mod=1e9+7,bit[]={1,3,7,15,31};
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,m,tot,qwq,txt[N],dfn[N];
int h[N],fa[N],dep[N],dis[N],tag[N];
int to[M][M],dp[N][M],pre[N],id[1<<15];
struct edge{int t,n,w;}e[N<<1];
struct bas{
	int a[5],flag;
	I ins(int x){
		ROF(i,4,0)if(x>>i&1){
			if(a[i])x^=a[i];
			else return a[i]=x,1;
		}
		return flag=1,0;
	}
	I comp(){return a[0]|a[1]<<1|a[2]<<3|a[3]<<6|a[4]<<10;}
	V assign(int x){a[0]=x&1,a[1]=x>>1&3,a[2]=x>>3&7,a[3]=x>>6&15,a[4]=x>>10;}
	I hash(){
		FOR(i,0,4)if(a[i]&&!(a[i]>>i&1))return -1;
		FOR(i,0,4)FOR(j,i+1,4)if(a[j]>>i&1)a[j]^=a[i];
		return comp();
	}
}t[N][2],tmp;
I merge(int x,int y){
	static bas tx,ty;tx.assign(x),ty.assign(y);
	FOR(i,0,4)if(ty.a[i]&&!tx.ins(ty.a[i]))return 2;
	return tx.hash();
}
V add_edge(int x,int y,int w){
	if(y-1)e[++tot]=(edge){y,h[x],w},h[x]=tot;
	if(x-1)e[++tot]=(edge){x,h[y],w},h[y]=tot;
}
I find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
V con(int x,int y){if(x-1&&y-1)fa[find(x)]=find(y);}
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)fa[i]=i;int x,y,w;
	while(m--)scanf("%d%d%d",&x,&y,&w),con(x,y),add_edge(x,y,w);
}
queue<int>q;
V bfs(){
	for(q.push(1);!q.empty();q.pop()){
		int u=q.front(),p=dfn[find(u)];
		REP(u)
			if(!dep[v])
				dep[v]=dep[u]+1,pre[v]=u,dis[v]=dis[u]^e[i].w,q.push(v);
			else if(u>v&&pre[u]!=v){
				if(dep[u]==dep[v]&&dep[u]==1)tag[p]=dis[u]^dis[v]^e[i].w;
				else t[p][0].ins(dis[u]^dis[v]^e[i].w);
			}
	}
}
V init(){
	FOR(i,2,n)if(!dfn[find(i)])dfn[find(i)]=++qwq;
	tot=0,memset(tag,-1,sizeof(tag)),bfs(),dp[0][1]=1;
	int p,x=0;
	FOR(i,0,(1<<15)-1){
		tmp.assign(i),p=tmp.hash();
		if(~p&&!id[p])txt[id[p]=++tot]=p;
	}
	FOR(i,1,qwq)if(~tag[i])t[i][1]=t[i][0],t[i][1].ins(tag[i]);
	FOR(i,1,tot)FOR(j,1,tot)to[i][j]=id[merge(txt[i],txt[j])];
}
V work(){
	int p,ans=0;
	FOR(i,1,qwq){
		if(!t[i][0].flag){
			p=id[t[i][0].hash()];
			FOR(j,1,tot)check(dp[i][to[j][p]]+=(dp[i-1][j]<<!!~tag[i])%mod);
		}
		if(~tag[i]&&!t[i][1].flag){
			p=id[t[i][1].hash()];
			FOR(j,1,tot)check(dp[i][to[j][p]]+=dp[i-1][j]);
		}
		FOR(j,1,tot)check(dp[i][j]+=dp[i-1][j]);
	}
	FOR(i,1,tot)check(ans+=dp[qwq][i]);
	cout<<ans<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}