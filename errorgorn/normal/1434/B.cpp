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
		val=max(val,j);
		if (s==e) return;
		if (i<=m) l->update(i,j);
		else r->update(i,j);
	}
	
	int query(int i,int j){
		if (j<i) return 0;
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

int n;
set<int> s;
int pos[100005];
int ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	char c;
	rep(x,0,2*n){
		cin>>c;
		
		if (c=='+'){
			s.insert(x);
		}
		else{
			int t;
			cin>>t;
			pos[t]=x;
			root->update(x,t);
		}
	}
	
	rep(x,1,n+1){
		auto it=s.lower_bound(pos[x]);
		if (it==s.begin()){
			cout<<"NO"<<endl;
			return 0;
		}
		
		it--;
		if (root->query(*it+1,pos[x]-1)>x){
			cout<<"NO"<<endl;
			return 0;
		}
		
		ans[*it]=x;
		s.erase(it);
	}
	
	cout<<"YES"<<endl;
	rep(x,0,2*n) if (ans[x]) cout<<ans[x]<<" ";
}