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
	int val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j){
		if (s==e){
			val+=j;
		}
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			val=l->val+r->val;
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root=new node(0,1000005);

int n,k;
int arr[500005];
int brr[500005];

vector<ii> fwd;
vector<ii> bwd;
int sub[500005];

vector<ii> edges;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x]>>brr[x];
	
	vector<int> uni={k};
	rep(x,0,n) uni.pub(arr[x]),uni.pub(brr[x]);
	sort(all(uni));
	uni.erase(unique(all(uni)),uni.end());
	map<int,int> id;
	rep(x,0,sz(uni)) id[uni[x]]=x;
	k=id[k];
	rep(x,0,n) arr[x]=id[arr[x]],brr[x]=id[brr[x]];
	
	//cout<<k<<endl;
	//rep(x,0,n) cout<<arr[x]<<" "<<brr[x]<<endl;
	
	rep(x,0,n) if (k<=arr[x]){
		if (brr[x]<=arr[x]) bwd.pub(ii(arr[x],brr[x]));
		else fwd.pub(ii(arr[x],brr[x]));
	}
	
	int bs=sz(bwd);
	
	sort(all(fwd),[](ii i,ii j){
		return i.se<j.se;
	});
	sort(all(bwd));
	reverse(all(bwd));
	
	rep(x,0,sz(fwd)){
		while (!bwd.empty() && bwd.back().fi<fwd[x].se){
			root->update(bwd.back().se,1);
			bwd.pob();
		}
		sub[x]=root->query(fwd[x].fi+1,1000005);
	}
	
	int curr=-1;
	int ans=0;
	
	rep(x,0,sz(fwd)) if (sub[x]==0){
		if (curr<=fwd[x].fi){
			curr=fwd[x].se;
			ans++;
		}
	}
	
	cout<<ans+bs<<endl;
}