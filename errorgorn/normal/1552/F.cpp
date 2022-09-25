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

const int MOD=998244353;

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
	
	void update(int i,int j,ll k){
		if (s==i && e==j) val=(val+k)%MOD;
		else if (j<=m) l->update(i,j,k);
		else if (m<i) r->update(i,j,k);
		else l->update(i,m,k),r->update(m+1,j,k);
	}
	
	ll query(int i){
		if (s==e) return val;
		else if (i<=m) return (l->query(i)+val)%MOD;
		else return (r->query(i)+val)%MOD;
	}
} *root=new node(0,200005);

int n;
int arr[200005];
int brr[200005];
int crr[200005];

vector<int> v;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x]>>brr[x]>>crr[x];
	
	ll ans=(arr[n]+1)%MOD;
	
	v.pub(arr[0]);
	
	rep(x,1,n+1){
		v.pub(arr[x]);
		
		int idx=lb(all(v),brr[x])-v.begin();
		
		ll w;
		if (idx==x) w=(arr[x]-brr[x])%MOD;
		else w=(
			arr[x]-arr[x-1]+ //go back to original
			root->query(idx)+ //do bullshit in middle
			arr[idx]-brr[x] //travel to middle checkpoint
		)%MOD;
		
		root->update(x,x,w);
		root->update(0,x-1,(w+arr[x]-arr[x-1])%MOD);
		
		if (crr[x]==1) ans=(ans+w)%MOD;
		//cout<<idx<<" "<<w<<" "<<arr[idx]-brr[x]<<endl;
	}
	
	cout<<ans<<endl;
}