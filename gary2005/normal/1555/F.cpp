/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=3e5+1;
const int MAXM=5e5+1;
int dfn[MAXN],heavy[MAXN],top[MAXN],n,q,siz[MAXN],fa[MAXN][19],dsu[MAXN],depth[MAXN],totop[MAXN],cnt;
bool ans[MAXM];
int u[MAXM],v[MAXM],x[MAXM];
vector<mp> g[MAXN];
int root(int x){
	return dsu[x]=(dsu[x]==x? x:root(dsu[x]));
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int dis=depth[u]-depth[v];
	rep(i,19) if((dis>>i)&1) u=fa[u][i];
	if(u==v) return u;
	rl(i,18,0) if(fa[u][i]!=fa[v][i]){
		u=fa[u][i];
		v=fa[v][i];
	}
	return fa[u][0];
}
void dfs1(int now,int pre){
	siz[now]=1;
	fa[now][0]=pre;
	rb(i,1,18){
		fa[now][i]=fa[fa[now][i-1]][i-1];
	}
	for(auto it:g[now]){
		if(it.FIR!=pre){
			totop[it.FIR]=totop[now]^it.SEC;
			depth[it.FIR]=depth[now]+1;
			dfs1(it.FIR,now);
			siz[now]+=siz[it.FIR];
		}
	}
}
void dfs2(int now,int pre){
	dfn[now]=++cnt;
	for(auto it:g[now]){
		if(it.FIR!=pre&&siz[it.FIR]>siz[heavy[now]]){
			heavy[now]=it.FIR;
		}
	}
	if(heavy[now]) top[heavy[now]]=top[now],dfs2(heavy[now],now);
	for(auto it:g[now]){
		if(it.FIR!=pre&&it.FIR!=heavy[now]){
			top[it.FIR]=it.FIR;
			dfs2(it.FIR,now);
		}
	}
}
const int N=1<<19;
LL tree[N+N];
int tag[N+N],Siz[N+N];
void pd(int now){
	tree[now]+=1ll*tag[now]*Siz[now];
	if(now<N){
		tag[now<<1]+=tag[now];
		tag[now<<1|1]+=tag[now];
	}
	tag[now]=0;
}
LL query(int a,int b,int now=1,int l=1,int r=N+1){
	pd(now);
	if(r<=a||l>=b) return 0;
	if(r<=b&&l>=a) return tree[now];
	int mid=(l+r)>>1;
	return query(a,b,now<<1,l,mid)+query(a,b,now<<1|1,mid,r);
}
void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
	pd(now);
	if(r<=a||l>=b) return ;
	if(r<=b&&l>=a){
		tag[now]+=val;
		pd(now);
		return ;
	}
	int mid=(l+r)>>1;
	add(a,b,val,now<<1,l,mid);
	add(a,b,val,now<<1|1,mid,r);
	tree[now]=tree[now<<1]+tree[now<<1|1];
}
void Add(int x,int val){
	while(x){
		add(dfn[top[x]],dfn[x]+1,val);
		x=fa[top[x]][0];
	}
}
LL Query(int x){
	LL val=0;
	while(x){
		val+=query(dfn[top[x]],dfn[x]+1);
		x=fa[top[x]][0];
	}
	return val;
}
int main(){
	scanf("%d%d",&n,&q);
	rb(i,1,N) Siz[i+N-1]=1;
	rl(i,N-1,1) Siz[i]=Siz[i<<1]<<1;
	rb(i,1,n) dsu[i]=i;
	rb(i,1,q){
		scanf("%d%d%d",&u[i],&v[i],&x[i]);
		if(root(u[i])!=root(v[i])){
//			cout<<u[i]<<" "<<v[i]<<endl;
			dsu[root(u[i])]=root(v[i]);
			g[u[i]].PB(II(v[i],x[i]));
			g[v[i]].PB(II(u[i],x[i]));
			ans[i]=1;
		}
	}
	rb(i,1,n) if(root(i)==i){
		dfs1(i,0);
		top[i]=i;
		dfs2(i,0);
	}
	rb(i,1,q){
		if(ans[i]) continue;
		int l=lca(u[i],v[i]);
		ans[i]=(
		x[i]!=(totop[u[i]]^totop[v[i]])
		&&
		Query(u[i])+Query(v[i])-2*Query(l)==0ll
		);
		if(ans[i]){
			Add(u[i],1);
			Add(v[i],1);
			Add(l,-2);
		}
	}
	rb(i,1,q){
		puts(ans[i]? "YES":"NO");
	}
	return 0;
}