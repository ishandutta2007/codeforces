#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,q,m;
ll icq300;
vector<pair<pair<ll,int>,int> >adj[100001];
int etv[100001];
ll w[100001];
int l[100001],r[100001];
int ptr=0;
void dfs(int id,int p){
	l[id]=r[id]=++ptr;
	for(auto cur:adj[id]){
		if(cur.fi.se==p) continue;
		etv[cur.se]=cur.fi.se;
		dfs(cur.fi.se,id);
		r[id]=++ptr;
	}
}
const int ts=524288;
ll mx1[ts],mx2[ts],mx3[ts],mx4[ts],mx5[ts];
ll lz[ts];
void pull(int id){
	int lc=id*2,rc=id*2+1;
	mx1[id]=max(mx1[lc],mx1[rc]);
	mx2[id]=max(mx2[lc],mx2[rc]);
	mx3[id]=max(mx3[lc],mx3[rc]);
	mx3[id]=max(mx3[id],mx1[lc]+mx2[rc]);
	mx4[id]=max(mx4[lc],mx4[rc]);
	mx4[id]=max(mx4[id],mx2[lc]+mx1[rc]);
	mx5[id]=max(mx5[lc],mx5[rc]);
	mx5[id]=max(mx5[id],max(mx3[lc]+mx1[rc],mx1[lc]+mx4[rc]));
}
void push(int id){
	int lc=id*2,rc=id*2+1;
	mx1[lc]+=lz[id];mx2[lc]-=2*lz[id];mx3[lc]-=lz[id];mx4[lc]-=lz[id];lz[lc]+=lz[id];
	mx1[rc]+=lz[id];mx2[rc]-=2*lz[id];mx3[rc]-=lz[id];mx4[rc]-=lz[id];lz[rc]+=lz[id];
	lz[id]=0;
}
void upd(int id,int l,int r,int ql,int qr,ll v){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		mx1[id]+=v;mx2[id]-=2*v;mx3[id]-=v;mx4[id]-=v;lz[id]+=v;
		return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr,v);
	upd(id*2+1,mid+1,r,ql,qr,v);
	pull(id);
}
void flush(int id,int l,int r){
	if(l==r) return;
	push(id);
	int mid=(l+r)/2;
	flush(id*2,l,mid);
	flush(id*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q >> icq300;
	m=2*n-1;
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v >> w[i];
		adj[u].push_back({{w[i],v},i});
		adj[v].push_back({{w[i],u},i});
	}
	dfs(1,0);
	for(int i=1; i<n ;i++){
		upd(1,1,m,l[etv[i]],r[etv[i]],w[i]);
	}
	ll ans=0;
	for(int i=1; i<=q ;i++){
		ll d,e;cin >> d >> e;
		d=(d+ans)%(n-1)+1;
		e=(e+ans)%icq300;
		int id=etv[d];
		upd(1,1,m,l[id],r[id],e-w[d]);
		w[d]=e;
		ans=mx5[1];
		cout << ans << '\n';
	}
}