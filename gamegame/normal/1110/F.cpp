#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,q;
int ptr=0;
vector<pair<ll,int> >c[500001];
vector<pair<ll,int> >adj[500001];
int pre[500001];
ll ans[500001];
ll mini[1048576];
inline void stupd(int id,int l,int r,int x,ll v){
	if(l==r){
		mini[id]=v;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) stupd(id*2,l,mid,x,v);
	else stupd(id*2+1,mid+1,r,x,v);
	mini[id]=min(mini[id*2],mini[id*2+1]);
}
inline ll stqry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql || mini[id]==1e18) return 1e18;
	if(ql<=l && r<=qr) return mini[id];
	int mid=(l+r)/2;
	return min(stqry(id*2,l,mid,ql,qr),stqry(id*2+1,mid+1,r,ql,qr));
}
void dfs(int id){
	pre[id]=++ptr;
	for(auto cur:c[id]) dfs(cur.se);
}
bool die[500001];
int sz[500001],boss[500001];
ll d[500001];
int tsz;
void dfs4(int id,int p){
	sz[id]=1;++tsz;
	for(auto cur:adj[id]){
		if(cur.se==p || die[cur.se]) continue;
		d[cur.se]=d[id]+cur.fi;
		dfs4(cur.se,id);
		sz[id]+=sz[cur.se];
	}
}
int get_mid(int id,int p){
	if(sz[id]*2<tsz) return 0;
	bool ok=true;
	int res=0;
	for(auto cur:adj[id]){
		if(cur.se==p || die[cur.se]) continue;
		if(res==0) res=get_mid(cur.se,id);
		if(sz[cur.se]*2>tsz) ok=false;
	}
	if(ok) res=id;
	return res;
}
void dfs3(int id,int p,int t){
	boss[id]=t;
	if(adj[id].size()==1) stupd(1,1,n,pre[id],d[id]);
	for(auto cur:adj[id]){
		if(cur.se==p || die[cur.se]) continue;
		d[cur.se]=d[id]+cur.fi;
		if(t==0) dfs3(cur.se,id,cur.se);
		else dfs3(cur.se,id,t);
	}
}
void dfs2(int id,int p){
	if(adj[id].size()==1) stupd(1,1,n,pre[id],1e18);
	for(auto cur:adj[id]){
		if(cur.se==p || die[cur.se]) continue;
		dfs2(cur.se,id);
	}
}
struct qry{
	int x,l,r,qid;
};
vector<qry>upd[500001];
qry cupd[500001];
void solve(int id){
	//cout << "solve " << id << endl;
	int usz=0;
	for(auto cur:upd[id]) cupd[++usz]=cur;
	upd[id].clear();
	tsz=0;
	dfs4(id,0);
	int mid=get_mid(id,0);
	d[mid]=0;
	dfs3(mid,0,0);
	for(int i=1; i<=usz ;i++){
		ans[cupd[i].qid]=min(ans[cupd[i].qid],d[cupd[i].x]+stqry(1,1,n,cupd[i].l,cupd[i].r));
		upd[boss[cupd[i].x]].push_back(cupd[i]);
	}
	dfs2(mid,0);
	die[mid]=true;
	for(auto cur:adj[mid])
		if(!die[cur.se]) solve(cur.se);
}
void in(int& x){
	char c=getchar();
	while(c<48 && c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
void in(ll& x){
	char c=getchar();
	while(c<48 && c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
int main(){
	ios::sync_with_stdio(false);
	in(n);in(q);
	for(int i=2; i<=n ;i++){
		int p;ll w;in(p);in(w);
		c[p].push_back({w,i});
		adj[p].push_back({w,i});
		adj[i].push_back({w,p});
	}
	dfs(1);
	for(int i=1; i<1048576 ;i++) mini[i]=1e18;
	for(int i=1; i<=q ;i++){
		int u,l,r;
		in(u);in(l);in(r);
		upd[1].push_back({u,l,r,i});
		ans[i]=1e18;
	}
	solve(1);
	for(int i=1; i<=q ;i++) cout << ans[i] << '\n'; 
}