// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m;
	ii val=ii(0,0);
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ii k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=max(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root1=new node(0,200005),*root2=new node(0,200005),*root3=new node(0,200005);

int n;
int arr[200005];

bool solve(int l,int r){
	int m=root1->query(l,r).se;
	
	int mx=root2->query(m,r).fi+root3->query(l-1,m-1).fi;
	if (arr[m]<mx) return true;
	
	if (l!=m && solve(l,m-1)) return true;
	if (m!=r && solve(m+1,r)) return true;
	return false;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) root1->update(x,ii(arr[x],x));
		
		int curr=0;
		rep(x,1,n+1){
			curr+=arr[x];
			root2->update(x,ii(curr,x));
			root3->update(x,ii(-curr,x));
		}
		
		if (!solve(1,n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}