//
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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

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
			val+=lazy*(e-s+1);
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
			val=l->val+r->val;
		}
	}
	
	int query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
	
	int find(int i){
		if (s==e) return s;
		
		propo();
		
		l->propo();
		if (l->val<i) return r->find(i-l->val);
		else return l->find(i);
	}
} *root=new node(0,400005);

int n,k;
int arr[200005];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x],arr[x]--;
	
	sort(arr,arr+n);
	reverse(arr,arr+n);
	
	root->update(0,0,1);
	
	int curr=0;
	int ans=1e9;
	rep(x,0,n){
		while (root->query(curr,curr)==0) curr++;
		
		root->update(curr,curr,-1);
		root->update(curr+2,curr+1+arr[x]/2,1);
		root->update(curr+2,curr+1+(arr[x]+1)/2,1);
		
		ans=min(ans,root->find(k));
	}
	
	if (ans>400000) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}