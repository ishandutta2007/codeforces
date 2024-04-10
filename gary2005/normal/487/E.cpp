/*
{By GWj
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define wtf cout<<'!'<<endl
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,low[200000+1],m,fa[200000+1][19],dfn[200000+1],siz[200000+1],top[200000+1],heavy[200000+1],cnt,depth[200000+1];
vector<int> g[200000+1],g2[200000+1];
bool vis[200000+10];
stack<int> st;
void dfs(int now,int pre=0,int deep=1){
	low[now]=depth[now]=deep;
	vis[now]=1;
	st.push(now); 
	for(auto it:g[now]){
		if(it==pre) continue;
		if(vis[it]){
			check_min(low[now],depth[it]);
		}
		else{
			dfs(it,now,deep+1);
			check_min(low[now],low[it]);
			if(low[it]>=depth[now]){
				int is;
				++cnt;
				do{
					is=st.top();
					st.pop();
					g2[cnt].PB(is);
					g2[is].PB(cnt);
				}while(is!=it);
				g2[now].PB(cnt);
				g2[cnt].PB(now);
			}
		}
	}
}
void dfs3(int now,int pre=0,int deep=1){
	depth[now]=deep+1;
	fa[now][0]=pre;
	rb(i,1,18)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g2[now]){
		if(it!=pre){
			dfs3(it,now,deep+1);
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	int jump=depth[v]-depth[u];
	rep(i,19){
		if((jump>>i)&1){
			v=fa[v][i];
		}
	}
	if(u==v) return v;
	rl(i,18,0){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
priority_queue<mp,vector<mp>,greater<mp> > qu[200000+1];
void dfs4(int now,int pre=0){
	siz[now]=1;
	for(auto it:g2[now]){
		if(it==pre) continue;
		dfs4(it,now);
		siz[now]+=siz[it];
	}
	for(auto it:g2[now]){
		if(it==pre) continue;
		if(siz[it]*2>=siz[now]){
			heavy[now]=it;
		}
	}
}
void dfs2(int now,int pre=0){
	dfn[now]=++cnt;
	if(heavy[now]){
		top[heavy[now]]=top[now];
		dfs2(heavy[now],now);
	}
	for(auto it:g2[now]){
		if(it==pre) continue;
		if(it==heavy[now]) continue;
		top[it]=it;
		dfs2(it,now);
	}
}
const int N=1<<18;
int tree[N<<1];
void modify(int index,int val){
	index+=N-1;
	tree[index]=val;
	index>>=1;
	while(index){
		tree[index]=min(tree[index<<1],tree[index<<1|1]);
		index>>=1;
	}
}
int query(int a,int b,int now,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return INF;
	}
	if(r<=b&&l>=a){
		return tree[now];
	}
	int mid=(l+r)>>1;
	return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r)); 
}
int query(int u,int v){
	if(v>n){
		v=fa[v][0];
	}
	assert(v<=n);
	assert(depth[u]>=depth[v]);
	int rest=INF;
	while(depth[u]>=depth[v]&&u){
		int is;
		if(depth[top[u]]<depth[v]){
			is=v;
		}
		else{
			is=top[u];
		}
		rest=min(rest,query(dfn[is],dfn[u]+1,1));	
		u=fa[is][0];
	}
	return rest;
}
int w[100000+1];
int main(){
	fastio;
	R2(n,m);
	cnt=n;
	int q;
	R(q);
	rb(i,1,n){
		R(w[i]);
	}
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);	
	}              
	dfs(1);
//	cout<<endl;
//	rb(i,1,cnt){
//		for(auto it:g2[i]){
//			if(it>i){
//				cout<<i<<" "<<it<<endl;
//			}
//		} 
//	} 
//	return 0;
	dfs3(1);
	dfs4(1);
	cnt=0;
	top[1]=1;
	dfs2(1);
	rb(i,1,n){
		if(fa[i][0]>n){
			qu[fa[i][0]].push(II(w[i],i));
		}
		modify(dfn[i],w[i]);
	} 
	rb(i,n+1,cnt){
		modify(dfn[i],qu[i].top().FIR);
	}
	rb(i,1,q){
		char ty;
		R(ty);
		if(ty=='C'){
			int a,w_;
			R2(a,w_);
			w[a]=w_;
			if(fa[a][0]>n){
				qu[fa[a][0]].push(II(w[a],a));
				while(1){
					int val,id;
					val=qu[fa[a][0]].top().FIR;
					id=qu[fa[a][0]].top().SEC;
					if(w[id]!=val){
						qu[fa[a][0]].pop();
					}
					else{
						break;
					}
				}
				modify(dfn[fa[a][0]],qu[fa[a][0]].top().FIR);
			}
			modify(dfn[a],w_);
		}
		else{
			int a,b;
			R2(a,b);
			int llc=lca(a,b);
			cout<<min(query(a,llc),query(b,llc))<<endl; 
		}
	}
	return 0;
}