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

struct node{
	int s,e,m;
	ll val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ll k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			val=l->val+r->val;
		}
	}
	
	ll query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root=new node(0,200005);

ll sum(ll i){
	return i*(i+1)/2;
}

int n,q;
int arr[200005];

set<int> s;
void update(int i){
	if (arr[i]>arr[i+1]){
		if (!s.count(i)){
			auto it=s.insert(i).fi;
			
			int l=*prev(it),r=*next(it);
			
			root->update(r,sum(r-i));
			root->update(i,sum(i-l));
		}
	}
	else{
		if (s.count(i)){
			auto it=s.find(i);
			
			int l=*prev(it),r=*next(it);
			
			root->update(r,sum(r-l));
			root->update(i,0);
			s.erase(it);
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	arr[0]=1e9+100,arr[n+1]=-1;
	
	s.insert(0);
	s.insert(n+1);
	rep(x,1,n+1) update(x);
	
	int a,b;
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a>>b;
			arr[a]=b;
			
			update(a);
			update(a-1);
		}
		else{
			cin>>a>>b;
			
			int l=*s.lower_bound(a);
			int r=*prev(s.upper_bound(b));
			
			if (r<l) cout<<sum(b-a+1)<<endl;
			else{
				ll ans=0;
				if (l!=r) ans+=root->query(l+1,r);
				ans+=sum(b-r);
				ans+=sum(l-a+1);
				
				cout<<ans<<endl; 
			}
		}
	}
}