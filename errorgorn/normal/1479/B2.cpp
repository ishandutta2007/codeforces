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
int arr[100005];

struct node{
	int s,e,m;
	int val=0,lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			
			lazy=0;
		}
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
	
	void set(int i,int j){
		propo();
		
		if (s==e) val=min(val,j);
		else{
			if (i<=m) l->set(i,j);
			else r->set(i,j);
			
			l->propo(),r->propo();
			val=min(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
	
} *root=new node(0,100005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	root->update(1,100005,1e9);
	
	int p=0;
	rep(x,0,n){
		//dont put with previous
		int val=min(
			min(root->query(0,arr[x]-1),root->query(arr[x]+1,100005))+1,
			root->query(arr[x],arr[x])
		);
		
		//we put with previous
		if (arr[x]!=p){
			root->update(0,100005,1);
		}
		
		root->set(p,val);
		
		p=arr[x];
		
		//rep(x,1,3) cout<<root->query(x,x)<<" "; cout<<endl;
	}
	
	cout<<root->query(0,100005)<<endl;
}