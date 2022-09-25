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

struct node{
	int s,e,m;
	ll val00,val01,val10,val11;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ll k){
		if (s==e){
			val00=k;
			val11=-k;
			val01=-1e15;
			val10=-1e15;
		}
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val00=max({l->val00+r->val10,l->val01+r->val00,l->val00,r->val00});
			val01=max({l->val00+r->val11,l->val01+r->val01,l->val01,r->val01});
			val10=max({l->val10+r->val10,l->val11+r->val00,l->val10,r->val10});
			val11=max({l->val10+r->val11,l->val11+r->val01,l->val11,r->val11});
		}
	}
} *root;

int n,q;
ll arr[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		root=new node(1,n);
		
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) root->update(x,arr[x]);
		
		cout<<max(root->val00,root->val01)<<endl;
		
		int a,b;
		while (q--){
			cin>>a>>b;
			swap(arr[a],arr[b]);
			root->update(a,arr[a]);
			root->update(b,arr[b]);
			cout<<max(root->val00,root->val01)<<endl;
		}
		
		cout<<endl;
	}
}