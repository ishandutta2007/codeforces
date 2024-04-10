#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
#define Maxn 500010
#define cout cerr
#define FR first
#define SE second
int head[Maxn],v[Maxn<<2],nxt[Maxn<<2],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

pii seq[Maxn];int cnt;
int fa[Maxn],depth[Maxn];
int dfs(int u){
	int x=u,s=0;
	for(int i=head[u];i;i=nxt[i])
		if(fa[v[i]]==-1){
			depth[v[i]]=depth[u]+1;fa[v[i]]=u;
			int h=dfs(v[i]);int t=depth[h]-depth[u];
			for(int j=1;j<=min(s,t);++j){
				seq[++cnt]=pii(h,x);
				h=fa[h];x=fa[x];
			}
			if(s<t)x=h;
			s=max(s,t)-min(s,t);
		}
	return x;
}
int path[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(m);
		tot=0;memset(head,0,sizeof(int)*(n+1));
		int s,e;
		for(int i=1;i<=m;++i){
			rd(s);rd(e);
			add_edge(s,e);
		}
		memset(fa,-1,sizeof(int)*(n+1));
		fa[1]=0;depth[1]=0;cnt=0;
		int u=dfs(1);
		if(depth[u]+1>=(n+1)/2){
			puts("PATH");
			int len=0;
			while(u!=1){
				path[++len]=u;
				u=fa[u];
			}
			path[++len]=1;
			printf("%d\n",len);
			for(int i=1;i<=len;++i)printf("%d ",path[i]);
			puts("");
		}else{
			puts("PAIRING");
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;++i)printf("%d %d\n",seq[i].FR,seq[i].SE);
		}
	}
	return 0;
}