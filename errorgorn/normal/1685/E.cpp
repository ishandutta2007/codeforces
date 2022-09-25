// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
int arr[200005];
int pos[200005];

struct node{
	int s,e,m;
	ii val;
	int lazy=0;
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
		if (lazy==0) return;
		val.fi+=lazy;
		if (s!=e){
			l->lazy+=lazy;
			r->lazy+=lazy;
		}
		lazy=0;
	}
	
	void update(int i,int j,int k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=min(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		propo();
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

struct dat{
	int l=-1,r=-1;
	bool ok=true;
};

dat merge(dat i,dat j){
	if (i.l==-1) return j;
	if (j.l==-1) return i;
	
	return {
		i.l,j.r,
		i.ok && j.ok && (i.r+1==j.l || i.r-n==j.l)
	};
}

struct node2{
	int s,e,m;
	dat val;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val.l=val.r=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=merge(l->val,r->val);
		}
	}
} *root2=new node2(0,200005),*root3=new node2(0,200005);

void del(int i,int j){
	if (j<=n) root->update(i,200005,1);
	if (j>=n+2) root->update(i,200005,-1);
	
	root2->update(i,-1);
	root3->update(i,-1);
}

void add(int i,int j){
	if (j<=n){
		root->update(i,200005,-1);
		root2->update(i,j);
	}
	if (j>=n+2){
		root->update(i,200005,1);
		root3->update(i,j);
	}
	if (j==n+1){
		root2->update(i,j);
		root3->update(i,j);
	}
}

void SWAP(int i,int j){
	del(i,arr[i]);
	del(j,arr[j]);
	
	swap(arr[i],arr[j]);
	swap(pos[arr[i]],pos[arr[j]]);
	
	add(i,arr[i]);
	add(j,arr[j]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,2*n+2) cin>>arr[x];
	rep(x,1,2*n+2) pos[arr[x]]=x;
	rep(x,1,2*n+2) add(x,arr[x]);
	
	int a,b;
	while (q--){
		cin>>a>>b;
		SWAP(a,b);
		
		// rep(x,1,2*n+2) cout<<arr[x]<<" "; cout<<endl;
		// rep(x,1,2*n+2) cout<<pos[x]<<" "; cout<<endl;
		
		int p=pos[n+1];
		int low=root->query(p,p).fi;
		
		if (root->query(0,p-1).fi<low){
			cout<<root->query(0,p-1).se<<endl;
		}
		else if (root->query(p+1,2*n+2).fi<low){
			cout<<root->query(p+1,2*n+2).se<<endl;
		}
		else if (!root3->val.ok){
			cout<<p-1<<endl;
		}
		else if (!root2->val.ok){ 
			cout<<p%(2*n+1)<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
}