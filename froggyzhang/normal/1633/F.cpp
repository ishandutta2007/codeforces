#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,f[N],top[N],son[N],siz[N],dep[N],dfn[N],num,fw[N],id[N],on[N];
vector<pair<int,int> > G[N];
class Segment_Tree{
	int Len;
	struct node{
		ll s[2];
		int g[2];
		bool rev;
		inline void Rev(){
			swap(s[0],s[1]),swap(g[0],g[1]);
			rev^=1;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		for(int i=0;i<2;++i){
			t[u].s[i]=t[ls].s[i]+t[rs].s[i];
			t[u].g[i]=t[ls].g[i]+t[rs].g[i];
		}
	}
	inline void pushdown(int u){
		if(t[u].rev){
			t[ls].Rev(),t[rs].Rev();
			t[u].rev=0;
		}
	}
	void build(int u,int L,int R){
		if(L==R){
			t[u].s[0]=fw[id[L]];
			t[u].g[0]=1;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void _change(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			t[u].Rev();
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_change(ls,L,mid,l,r);
		if(r>mid)_change(rs,mid+1,R,l,r);
		update(u);
	}
public:
	void init(int _n){
		Len=n;
		build(1,1,Len);
	}
	inline pair<ll,int> get_ans(){
		return make_pair(t[1].s[1],t[1].g[1]);
	}
	void Change(int l,int r){
	//	cerr<<" ?? "<<l<<" "<<r<<endl;
		_change(1,1,Len,l,r);
	}
}T;
void dfs1(int u){
	siz[u]=1;
	for(auto [v,id]:G[u]){
		if(v==f[u])continue;
		dep[v]=dep[u]+1,f[v]=u;
		fw[v]=id;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	dfn[u]=++num;
	id[num]=u;
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto [v,id]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
void work(int u){
	while(u){
		T.Change(dfn[top[u]],dfn[u]);
		u=f[top[u]];
	}
}
vector<int> ans;
bool dfs(int u){
	if(!on[u])return 0;
	bool jb=1;
	for(auto [v,id]:G[u]){
		if(v==f[u])continue;
		if(dfs(v)){
			jb=0;
			ans.push_back(id);
		}
	}
	return jb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}
	dfs1(1);
	dfs2(1,1);
	T.init(n);
	work(1);
	on[1]=1;
	int cnt=1;
	bool ok=0;
	while(true){
		int opt;
		cin>>opt;
		assert(opt);
		if(opt==3)break;
		if(opt==1){
			int u;
			cin>>u;
			assert(u);
			++cnt;
			work(u);
			on[u]=1;
			auto [sum,jb]=T.get_ans();
			if(cnt%2==0&&jb==cnt/2){
				cout<<sum<<endl;
				ok=1;
			}
			else{
				cout<<0<<endl;
				ok=0;
			}
		}
		else{
			if(!ok){
				cout<<0<<endl;
			}
			else{
				cout<<cnt/2<<' ';
				ans.clear();
				dfs(1);
				sort(ans.begin(),ans.end());
				for(auto x:ans)cout<<x<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}