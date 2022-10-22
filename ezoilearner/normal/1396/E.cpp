#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll K;
#define cout cerr
#define Maxn 100010
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int siz[Maxn],mx[Maxn],rt;
int depth[Maxn];//remember to initial
int *son[Maxn],at[Maxn];//at initial len
bool vis[Maxn];int seq[Maxn],T=0;
void findroot(int u,int f){
	siz[u]=1;mx[u]=0;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			findroot(v[i],u);
			mx[u]=max(mx[u],siz[v[i]]);
			siz[u]+=siz[v[i]];
		}
	mx[u]=max(mx[u],n-siz[u]);
	if(!rt||mx[u]<mx[rt])rt=u;
}
bool leaf[Maxn];
int deg[Maxn];
struct B{
	int *head,*v,*nxt,tot=0,Top;//remember to del and add
	void init(int siz){
		siz++;
		head=new int[siz+2];memset(head,0,sizeof(int)*(siz+2));
		v=new int[siz+2];memset(v,0,sizeof(int)*(siz+2));
		nxt=new int[siz+2];memset(nxt,0,sizeof(int)*(siz+2));
		Top=siz+1;
	}
	void add_edge(int dep,int u){//dep can be also use as siz
		tot++;v[tot]=u;nxt[tot]=head[dep];head[dep]=tot;
	}
	void Del(int dep){head[dep]=nxt[head[dep]];}
	pair<int,int> query(){
		while(!head[Top])Top--;
		return make_pair(v[head[Top]],Top);
	}
}B[Maxn];
ll L,R;
int bel[Maxn];
void pre_dfs(int u,int f){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			pre_dfs(v[i],u);
			siz[u]+=siz[v[i]];
		}
}
int fa[Maxn];
void dfs(int u,int f,int tp){
	vis[u]=true;bel[u]=tp;
	at[u]=0;
	L+=depth[u];R+=depth[u];
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			fa[v[i]]=u;
			depth[v[i]]=depth[u]+1;
			dfs(v[i],u,tp);
			at[u]++;
		}
	son[u]=new int[at[u]+1];
	son[u][0]=0;
	at[u]=0;
	if(at[u]==0)leaf[u]=true;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			at[u]++;
			son[u][at[u]]=v[i];
			if(!leaf[v[i]])deg[u]++;
		}
	if(u!=rt&&!deg[u]){
		B[tp].add_edge(depth[u],u);
	}
	if(u!=rt)L-=siz[u]/2*2;
}
void search(int u,int f){
	if(vis[u])seq[++T]=u;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f)search(v[i],u);
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

char num[20];int numst;
void print(int x){
	if(x==0)putchar('0');
	else{
		numst=0;
		while(x){
			num[++numst]='0'+x%10;
			x/=10;
		}
		while(numst){
			putchar(num[numst]);
			numst--;
		}
	}
}
void output(int x,int y){
	vis[x]=vis[y]=false;
	print(x);putchar(' ');print(y);puts("");
}

int main(){
	rd(n);scanf("%lld",&K);
	int s,e;
	for(int i=1;i<n;++i){
		rd(s);rd(e);
		add_edge(s,e);
	}
	rt=0;findroot(1,0);
	pre_dfs(rt,0);
	for(int i=head[rt];i;i=nxt[i])B[v[i]].init(siz[v[i]]);
	B[0].init(2*n);
	depth[rt]=0;
	vis[rt]=true;
	for(int i=head[rt];i;i=nxt[i]){
		fa[v[i]]=rt;
		depth[v[i]]=1;
		dfs(v[i],rt,v[i]);
		B[0].add_edge(siz[v[i]],v[i]);
	}
	if(K<L||R<K||(K-L)&1){
		puts("NO");
		return 0;
	}
	puts("YES");
	ll sum=0,To=(R-K)/2;
	while(To){
		pair<int,int> tmp=B[0].query();
		int node=tmp.first,siz=tmp.second;
		while(true){
			tmp=B[node].query();
			int u=tmp.first;
			while(at[u]&&!vis[son[u][at[u]]])at[u]--;
			if(at[u]==0){
				B[node].Del(tmp.second);
			}else break;
		}
		tmp=B[node].query();
		int u=tmp.first;
		if(depth[u]>To){
			while(depth[u]>To+1)u=fa[u];
			output(u,fa[u]);
			To=0;
			break;
		}else{
			To-=depth[u];
			int z=at[u]-1,b=son[u][at[u]];
			while(z&&!vis[son[u][z]])z--;
			if(!z){
				output(u,b);
				B[bel[u]].Del(depth[u]);
				if(fa[u]!=rt){
					deg[fa[u]]--;
					if(!deg[fa[u]])B[bel[u]].add_edge(depth[fa[u]],fa[u]);
				}
			}else{
				output(b,son[u][z]);
				at[u]=z-1;
				while(at[u]&&!vis[son[u][at[u]]])at[u]--;
				if(!at[u]&&fa[u]!=rt){//it's rt not 1
					deg[fa[u]]--;
					if(!deg[fa[u]])B[bel[u]].add_edge(depth[fa[u]],fa[u]);
				}
			}
		}
		B[0].Del(siz);
		siz-=2;if(siz>1)B[0].add_edge(siz,node);
	}
	search(rt,0);
	for(int i=1;i<=T/2;++i)output(seq[i],seq[i+T/2]);
	return 0;
}