//
//
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;
 
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
 
ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}
 
#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
struct node{
	int s,e,m;
	ii val;
	ll lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		val=ii(0,s);
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val.fi+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			
			lazy=0;
		}
	}
	
	void update(int i,int j,ll k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=max(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
};
 
struct mxnode{
	int s,e,m;
	ll val=0;
	mxnode *l,*r;
	
	mxnode (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new mxnode(s,m);
			r=new mxnode(m+1,e);
		}
	}
	
	void update(int i,ll j){
		if (s==e) val=j;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=max(l->val,r->val);
		}
	}
} *mxroot=new mxnode(0,100005);
 
ll n,q,w;
vector<ii> al[100005];
 
bool used[100005];
int ss[100005];
 
void dfs_c(int i,int p){
	ss[i]=1;
 
	for (auto &it:al[i]){
		if (it.fi==p || used[it.fi]) continue;
		
		dfs_c(it.fi,i);
		ss[i]+=ss[it.fi];
	}
}
 
ll cw[100005];
vector<ii> range[100005];
vector<ii> subtree[100005];
vector<ii> pos[100005];
node* root[100005];
 
bool degen[100005];
 
int TIME;
ii dfs(int i,int p,int root){
	ii r=ii(1e9,-1e9);
	
	for (auto &it:al[i]){
		if (it.fi==p || used[it.fi]) continue;
		
		auto temp=dfs(it.fi,i,root);
		
		if (i==root){
			rep(x,temp.fi,temp.se+1) subtree[root].push_back(temp);
		}
		
		pos[it.se].push_back(ii(root,sz(range[root])));
		range[root].push_back(temp);
		
		r.fi=min(r.fi,temp.fi);
		r.se=max(r.se,temp.se);
	}
	
	if (r==ii(1e9,-1e9)){
		r=ii(TIME,TIME);
		TIME++;
	}
	
	return r;
}
 
void centroid(int i){
	//cout<<i<<" "<<sz<<endl;
 
	dfs_c(i,-1);
	int sz=ss[i];
	
	int p=-1;
	reloop:
	for (auto &it:al[i]){
		if (it.fi==p || used[it.fi]) continue;
		
		if (ss[it.fi]>sz/2){
			p=i;
			i=it.fi;
			goto reloop;
		}
	}
	
	if (sz!=1){
		TIME=1;
		subtree[i].push_back(ii(1,1));
		root[i]=new node(0,dfs(i,-1,i).se+1);
	}
	else{
		degen[i]=true;
	}
	
	used[i]=true;
	
	for (auto &it:al[i]){
		if (it.fi==p || used[it.fi]) continue;
		
		centroid(it.fi);
	}
	
	if (p!=-1) centroid(p);
}
 
void get(int i){
	auto temp=root[i]->query(root[i]->s,root[i]->e);
	mxroot->update(i,temp.fi+max(root[i]->query(root[i]->s,subtree[i][temp.se].fi-1),root[i]->query(subtree[i][temp.se].se+1,root[i]->e)).fi);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q>>w;
	
	ll a,b,c;
	rep(x,0,n-1){
		cin>>a>>b>>c;
		
		al[a].push_back(ii(b,x));
		al[b].push_back(ii(a,x));
		cw[x]=c;
	}
	
	centroid(1);
	
	rep(x,0,n-1){
		for (auto &it:pos[x]){
			root[it.fi]->update(range[it.fi][it.se].fi,range[it.fi][it.se].se,cw[x]);
		}
	}
	
	rep(x,1,n+1){
		if (degen[x]) continue;
		
		get(x);
	}
	
	ll last=0;
	ll d,e;
	while (q--){
		cin>>d>>e;
		
		d=(d+last)%(n-1);
		e=(e+last)%w;
		
		for (auto &it:pos[d]){
			root[it.fi]->update(range[it.fi][it.se].fi,range[it.fi][it.se].se,e-cw[d]);
			get(it.fi);
		}
		cw[d]=e;
		
		last=mxroot->val;
		cout<<last<<endl;
	}
}