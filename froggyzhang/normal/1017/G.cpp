#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,Q;
vector<int> G[N];
int dfn[N],num,id[N],top[N],son[N],siz[N],dep[N],f[N];
struct Data{
	int sum,mx;
	Data(int _a=0,int _b=-1){sum=_a,mx=_b;}
	friend Data operator + (const Data &a,const Data &b){
		return Data(a.sum+b.sum,max(b.mx,a.mx+b.sum));
	}
};
class Segment_Tree{
	struct node{
		Data z;
		int cov,len;
		void Cover(int d){
			z.sum=len*d,z.mx=d;
			cov=-1;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(t[u].cov){
			t[ls].Cover(t[u].cov);
			t[rs].Cover(t[u].cov);
			t[u].cov=0;
		}
	}
	inline void update(int u){
		t[u].z=t[ls].z+t[rs].z;
	}
public:
	void build(int u,int L,int R){
		t[u].len=R-L+1;t[u].z.sum=-t[u].len;
		t[u].z.mx=-1;t[u].cov=0;
		if(L==R)return;
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void Cover(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			t[u].Cover(-1);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r);
		if(r>mid)Cover(rs,mid+1,R,l,r);
		update(u);
	}
	void Change(int u,int L,int R,int p,int d){
		if(L==R){
			t[u].z.mx+=d;
			t[u].z.sum+=d;
			return;	
		}	
		pushdown(u);
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,d):Change(rs,mid+1,R,p,d);
		update(u);
	}
	Data Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].z;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return Query(ls,L,mid,l,r)+Query(rs,mid+1,R,l,r);
		if(l<=mid)return Query(ls,L,mid,l,r);
		return Query(rs,mid+1,R,l,r);
	}
}T;
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
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
int Ask(int u){
	Data ans;
	while(u){
		ans=T.Query(1,1,n,dfn[top[u]],dfn[u])+ans;
		u=f[top[u]];
	}
	return ans.mx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	T.build(1,1,n);
	while(Q--){
		int opt,u;
		cin>>opt>>u;
		if(opt==1){
			T.Change(1,1,n,dfn[u],1);
		}
		else if(opt==2){
			T.Cover(1,1,n,dfn[u],dfn[u]+siz[u]-1);
			int w=Ask(u)+1;
			T.Change(1,1,n,dfn[u],-w);
		}
		else{
			cout<<(Ask(u)>=0?"black\n":"white\n");	
		}
	}
	return 0;
}