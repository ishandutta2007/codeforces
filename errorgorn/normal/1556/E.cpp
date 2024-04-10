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
	ii val;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	ii merge(ii a,ii b){
		return {
			min(a.fi,b.fi),
			max(a.se,b.se)
		};
	}
	
	void update(int i,ii k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else if (m<i) r->update(i,k);
			val=merge(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return merge(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,100005);

int n,q;
int arr[100005];
int brr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) cin>>brr[x];
	
	rep(x,1,n+1) arr[x]-=brr[x];
	
	rep(x,1,n+1) arr[x]+=arr[x-1];
	//rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
	
	rep(x,1,n+1) root->update(x,{arr[x],arr[x]});
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		auto temp=root->query(a-1,b);
		if (arr[a-1]!=arr[b] || temp.se>arr[b]) cout<<"-1"<<endl;
		else cout<<temp.se-temp.fi<<endl;
	}
}