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
#define debug(x) cout << #x << " is " << x << endl

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

int n;
vector<ii> v;

struct node{
	int s,e,m;
	ll val=1e9+69;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j,ll k){
		if (s==i && e==j) val=min(val,k);
		else if (j<=m) l->update(i,j,k);
		else if (m<i) r->update(i,j,k);
		else l->update(i,m,k),r->update(m+1,j,k);
	}
	
	ll query(int i){
		if (s==e) return val;
		else{
			if (i<=m) return min(val,l->query(i));
			else return min(val,r->query(i));
		}
	}
} *root=new node(0,100005),*root2=new node(0,100005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,0,n){
		cin>>a>>b;
		v.pub(ii(a,b));
	}
	
	sort(all(v));
	
	//for (auto &it:v) cout<<it.fi<<" "<<it.se<<endl;
	
	root->update(0,0,0);
	
	rep(x,0,n){
		ll val=min(root->query(x),root2->query(x)+v[x].fi);
		
		ll thres=v[x].fi+v[x].se;
		
		int lo=x,hi=n,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (v[mi].fi>=thres) hi=mi;
			else lo=mi;
		}
		
		root2->update(hi,100005,val-thres);
		root->update(x,lo,val);
	}
	
	ll ans=min(root->query(n-1),root2->query(n-1)+v[n-1].fi);
	for (auto &it:v) ans+=it.se;
	
	cout<<ans<<endl;
}