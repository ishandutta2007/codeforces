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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=  1e5+20;
int n;
int cf[MAXN];
	vector<int> g[MAXN];
	map<mp,int> ID;
	int CCNT=0,heavy[MAXN],SIZ[MAXN],top[MAXN],fa[MAXN][21],depth[MAXN],cnt=0,id[MAXN];
	void link(int u,int v){
		//TWO-WAY
		g[u].PB(v);
		g[v].PB(u);
		ID[II(u,v)]=ID[II(v,u)]=++CCNT;
	}
	void dfs(int now,int prev=0,int deep=1){
		depth[now]=deep;
		fa[now][0]=prev;
		rb(i,1,20){
			fa[now][i]=fa[fa[now][i-1]][i-1];
		}
		SIZ[now]=1;
		heavy[now]=-1;
		for(auto it:g[now]){
			if(it!=prev) {
			dfs(it,now,deep+1),SIZ[now]+=SIZ[it];
			}
		}
		for(auto it:g[now]){
			if(it!=prev){
				if(SIZ[it]*2>=SIZ[now]){
					heavy[now]=it;
				}
			}
		}
	}
	int lca(int u,int v){
	if(depth[u]>depth[v]){
		swap(u,v);
	}
	rl(i,20,0){
		if(fa[v][i]&&depth[fa[v][i]]>=depth[u]){
			v=fa[v][i];
		}
	}
	if(u==v) return u;
	rl(i,20,0){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
	}
	void dfs2(int now,int prev=-1){
		if(prev==-1) top[now]=now;
		if(heavy[now]>0){
			top[heavy[now]]=top[now];
			id[ID[II(now,heavy[now])]]=++cnt;
			dfs2(heavy[now],now);
		}
		for(auto it:g[now]){
			if(it!=prev){
				if(it!=heavy[now]){
					top[it]=it;
					id[ID[II(now,it)]]=++cnt;
					dfs2(it,now);
				}
			}
		}
	}
	void value(int l,int r){
		if(l>r) swap(r,l);
		cf[l]++;
		cf[r+1]--;
	}
	void  ask(int now,int to){
		if(now==to) return;
		if(top[now]==now){
			value(id[ID[II(now,fa[now][0])]],id[ID[II(now,fa[now][0])]]);
			ask(fa[now][0],to);
		}
		else{
			if(depth[top[now]]>=depth[to])
			{
				value(id[ID[II(now,fa[now][0])]],id[ID[II(top[now],heavy[top[now]])]]);
				ask(top[now],to);
			}
			else{
				value(id[ID[II(now,fa[now][0])]],id[ID[II(to,heavy[to])]]);	
			}
		}
	}
	void  query(int u,int v){
		//u->v
		int LCA=lca(u,v);
		ask(u,LCA);
		ask(v,LCA);
	}
//ATTENTION : REMEMBER TO MEMSET "FA"
int save[MAXN][2];
int main(){
	fastio;
	get(n);
	rb(i,1,n-1){
		int u,v;
		get2(u,v);
		save[i][0]=u;
		save[i][1]=v;
		link(u,v);
	}
	memset(fa,0,sizeof(fa));
	dfs(1);
	dfs2(1);
	int k;
	get(k);
	rb(i,1,k){
		vector<mp> modify;
		int u,v;
		get2(u,v);
		query(u,v);
	}
	rb(i,1,n)
		cf[i]+=cf[i-1];
	rb(i,1,n-1){
		int u,v;
		u=save[i][0];
		v=save[i][1];	
		cout<<cf[id[ID[II(u,v)]]]<<" ";
	}cout<<endl;
	return 0;
}