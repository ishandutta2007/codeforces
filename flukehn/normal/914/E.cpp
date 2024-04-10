#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=2e5+11;
struct Edge{
	int v;Edge*nxt;
}pl[N<<1],*cur=pl,*G[N];
inline void ins(int u,int v){*cur=(Edge){v,G[u]},G[u]=cur++;}
int n,S,rt,sz[N],gg[N];
char s[N],vis[N];
inline void findrt(int x,int fa=0){
	sz[x]=1,gg[x]=0;
	Es(x,i)if(!vis[i->v]&&i->v!=fa){
		findrt(i->v,x);
		sz[x]+=sz[i->v];
		gg[x]=max(gg[x],sz[i->v]);
	}
	gg[x]=max(gg[x],S-sz[x]);
	if(gg[rt]>gg[x])rt=x;
}
const int M=1<<21;
int cnt[M];
ll f[N],f2[N],g[M];
inline void DFS(int x,int fa=0){
	sz[x]=1,f2[x]=0;
	Es(x,i)if(!vis[i->v]&&i->v!=fa){
		DFS(i->v,x);
		sz[x]+=sz[i->v]; 
	}
}
int fx;
inline void dfs_add(int x,int now,int fa=0){
	now^=(1<<s[x]-'a');
	g[now]+=fx;
	Es(x,i)if(!vis[i->v]&&i->v!=fa){
		dfs_add(i->v,now,x);
	}
}
inline void dfs_cal(int x,int now,int fa=0){
	now^=(1<<s[x]-'a');
	f2[x]=g[now];
	rep(i,'a','t'){
		f2[x]+=g[now^(1<<i-'a')];
	}
	//dbg(x),dbg(f2[x]);
	Es(x,i)if(!vis[i->v]&&i->v!=fa){
		dfs_cal(i->v,now,x);
		f2[x]+=f2[i->v];
	}
	f[x]+=f2[x];
//	if(rt==1)debug("x : %d f2[x] : %d\n",x,f2[x]);
}
inline void dfs_cc(int x,int now,int fa=0){
	now^=(1<<s[x]-'a');
	f2[x]=(cnt[now]<=1);
	Es(x,i)if(!vis[i->v]&&i->v!=fa){
		dfs_cc(i->v,now,x);
		f2[x]+=f2[i->v];
	}
	f[x]+=f2[x];
}
inline void solve(int x){
//	dbg(x);
//	dbg(f[x]);
	vis[x]=1,DFS(x);
//	dbg(f2[x]);
	fx=1;
	Es(x,i)if(!vis[i->v]){
		dfs_add(i->v,0);
	}
	Es(x,i)if(!vis[i->v]){
		fx=-1,dfs_add(i->v,0);
		dfs_cal(i->v,1<<s[x]-'a');
		f2[x]+=f2[i->v];
		fx=1,dfs_add(i->v,0);
	}
	f[x]+=f2[x]/2;
//	dbg(f2[x]);
//	dbg(f[x]);
	fx=-1;
	Es(x,i)if(!vis[i->v]){dfs_add(i->v,0);}
	dfs_cc(x,0);
	Es(x,i)if(!vis[i->v]){
		S=sz[i->v],rt=0;
		findrt(i->v);
		solve(rt); 
	}
}
int main(){
#ifdef flukehn
	freopen("in.txt","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	For(i,1,M)cnt[i]=cnt[i^(i&-i)]+1;
	cin>>n;
	rep(_,2,n){
		int u,v;
		cin>>u>>v;
		ins(u,v),ins(v,u);
	}
	cin>>s+1;
	S=n,gg[rt=0]=inf,findrt(1),solve(rt);
	rep(i,1,n)printf("%lld%c",f[i]," \n"[i==n]);
}