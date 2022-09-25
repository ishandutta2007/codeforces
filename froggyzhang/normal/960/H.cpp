#include<bits/stdc++.h>
using namespace std;
#define N 50050
typedef long long ll;
int n,m,Q,C,a[N],b[N];
vector<int> G[N];
pair<ll,ll> operator + (const pair<ll,ll> &a,const pair<ll,ll> &b){
	return make_pair(a.first+b.first,a.second+b.second);
}
class Segment_Tree{
	int Len,cnt,rt[N];
	struct node{
		int len,add,ch[2];
		pair<ll,ll> sum;
		inline void Add(int d){
			sum.second+=1LL*d*d*len+2LL*d*sum.first;
			sum.first+=1LL*len*d;
			add+=d;
		}
	}t[N*100];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	inline void update(int u){
		t[u].sum=t[ls].sum+t[rs].sum;
	}
	inline void pushdown(int u){
		if(t[u].add){
			if(!ls)ls=++cnt,t[ls].len=(t[u].len+1)/2;
			if(!rs)rs=++cnt,t[rs].len=t[u].len/2;
			t[ls].Add(t[u].add);
			t[rs].Add(t[u].add);
			t[u].add=0;
		}
	}
	void _plus(int &u,int L,int R,int l,int r,int d){
		if(!u)u=++cnt,t[u].len=R-L+1;
		if(L>=l&&R<=r){
			t[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_plus(ls,L,mid,l,r,d);
		if(r>mid)_plus(rs,mid+1,R,l,r,d);
		update(u);
	}
public:
	void init(int _n){
		Len=_n;
	}
	void Plus(int x,int l,int r,int d){
		if(l>r)return;
		_plus(rt[x],1,Len,l,r,d);
	}
	pair<ll,ll> Query(int x){
		return t[rt[x]].sum;	
	}
}T;
int dfn[N],top[N],siz[N],son[N],f[N],num;
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
void Change(int u,int c,int d){
	while(u){
		T.Plus(c,dfn[top[u]],dfn[u],d);
		u=f[top[u]];
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(8);
	cin>>n>>m>>Q>>C;
	T.init(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i){
		Change(i,a[i],1);
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
	}
	while(Q--){
		int opt,x;
		cin>>opt>>x;
		if(opt==1){
			int w;
			cin>>w;
			Change(x,a[x],-1);
			a[x]=w;
			Change(x,a[x],1);
		}
		else{
			auto [s1,s2]=T.Query(x);
			double ans=1LL*C*C+(1LL*b[x]*b[x]*s2-2LL*C*s1*b[x])*1.0/n;
			cout<<ans<<'\n';	
		}
	}
	return 0;
}