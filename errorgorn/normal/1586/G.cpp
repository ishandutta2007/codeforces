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

const int MOD=1000000007;

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
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
		}
	}
	
	int query(int i){
		if (s==e) return val;
		else if (i<=m) return (val+l->query(i))%MOD;
		else return (val+r->query(i))%MOD;
	}
} *root=new node(0,400005);

int n,t;
int arr[200005];
int brr[200005];
bool need[200005];

vector<int> id;

int add[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x]>>brr[x];
	
	cin>>t;
	int a;
	rep(x,0,t){
		cin>>a;
		need[a-1]=true;
	}
	
	rep(x,0,n) id.pub(x);
	
	sort(all(id),[](int i,int j){
		return brr[i]<brr[j];
	});
	
	memset(add,-1,sizeof(add));
	
	int p=0;
	ll ans=0;
	
	rep(x,n,0) if (need[id[x]]){
		if (p<arr[id[x]]){
			add[id[x]]=p;
			p=arr[id[x]];
			ans++;
		}
	}
	
	//rep(x,0,n) cout<<add[x]<<" "; cout<<endl;
	
	rep(xx,0,n){
		int x=id[xx];
		//cout<<x<<" "<<arr[x]<<" "<<brr[x]<<endl;
		
		if (add[x]!=-1){
			//cout<<"debug: "<<x<<" "<<add[x]<<" "<<root->query(add[x])<<endl;
			ans=(ans+root->query(add[x]))%MOD;
		}
		
		root->update(0,arr[x],root->query(arr[x])+1);
	}
	
	cout<<ans<<endl;
}