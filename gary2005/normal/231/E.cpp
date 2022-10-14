/*
AuThOr Gwj
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+20;
const int MOD=1e9+7;
int n,m,id[MAXN],vis[MAXN],fa[MAXN][18],top[MAXN],heavy[MAXN],siz[MAXN],tree[MAXN],dfn[MAXN];

LL val2[MAXN],val[MAXN],inv[MAXN];
int cnt,low[MAXN],depth[MAXN];
vector<int> g[MAXN];
stack<int> s;
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
void dfs(int now,int pre,int deep){
	vis[now]=1;
	low[now]=now;
	depth[now]=deep;
	s.push(now);
	for(auto it:g[now]){
		if(it!=pre){
			if(vis[it]){
				if(depth[it]<depth[low[now]]){
					low[now]=it;
				}
			}
			else{
				dfs(it,now,deep+1);
				if(depth[low[it]]<depth[low[now]]){
					low[now]=low[it];
				}
			}
		}
	} 
	if(low[now]==now){
		cnt++;
		while(!s.empty()){
			int index=s.top();
			s.pop();
			id[index]=cnt;
			if(index==now) break;
		}
	}
}
LL query(int l,int r){
	return val[r]*inv[l-1]%MOD;
}
void dfs1(int now,int pre,int deep){
	fa[now][0]=pre;
	rb(i,1,17)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	tree[now]=cnt;
	siz[now]=1;
	depth[now]=deep;
	for(auto it:g[now]){
		if(it!=pre){
			dfs1(it,now,deep+1);
			siz[now]+=siz[it];
		}
	}
	for(auto it:g[now]){
		if(it!=pre){
			if(siz[it]*2>=siz[now]){
				heavy[now]=it;
			}
		}
	}
}
void dfs2(int now,int pre){
	dfn[now]=++cnt;
	if(heavy[now]){
		top[heavy[now]]=top[now];
		dfs2(heavy[now],now);
	}
	for(auto it:g[now]){
		if(it!=pre&&it!=heavy[now]){
			top[it]=it;
			dfs2(it,now);
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v]){
		swap(u,v);
	}
	rl(i,17,0){
		if(fa[v][i]&&depth[fa[v][i]]>=depth[u]){
			v=fa[v][i];
		}
	}
	if(u==v) return u;
	rl(i,17,0){
		if(fa[u][i]&&fa[v][i]&&fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[v][0];
}
LL calc(int u,int l){
	LL res=1;
	while(u&&depth[u]>=depth[l]){
		if(depth[top[u]]>=depth[l]){
			res*=query(dfn[top[u]],dfn[u]);
		}
		else{
			res*=query(dfn[l],dfn[u]);
		}
		res%=MOD;
		u=fa[top[u]][0];
	}
	return res;
}
int main(){
	fastio;
	R2(n,m);
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		edges.PB(II(u,v));
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n)
		if(!vis[i]) dfs(i,0,1);
	rb(i,1,n){
		if(!val2[id[i]]){
			val2[id[i]]=1;
		}
		else{
			val2[id[i]]=2;
		}
	}
	rb(i,1,n)
		g[i].clear();
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		if(id[u]!=id[v]){
			g[id[u]].PB(id[v]);
			g[id[v]].PB(id[u]);
		}
	}
	n=cnt;
	rb(i,1,n)
	{
		sort(ALL(g[i]));
		g[i].erase(unique(ALL(g[i])),g[i].end());
	}
	val[0]=1;
	inv[0]=1;
	cnt=0;
	rb(i,1,n){
		if(!tree[i]){
			cnt++;
			dfs1(i,0,1);
		} 
	}
	cnt=0;
	rb(i,1,n){
		if(fa[i][0]==0){
			top[i]=i;
			dfs2(i,0);
		}
	}
	rb(i,1,n)
		val[dfn[i]]=val2[i];
	rb(i,1,n)
		val[i]*=val[i-1],val[i]%=MOD,inv[i]=quick(val[i],MOD-2);
	int q;
	cin>>q;
	while(q--){
		int u,v;
		R2(u,v);
		u=id[u];
		v=id[v];
		if(tree[u]!=tree[v]){
			cout<<0<<endl;
		}
		else
		{
			int l=lca(u,v);
			cout<<calc(u,l)*calc(v,l)%MOD*quick(val2[l],MOD-2)%MOD<<endl; 
		}
	}
	return 0;
}