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
	ii val;
	int lazy=1e9;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val={1e9,1e9};
		}
		else{
			val={1e9,-1e9};
		}
	}
	
	void propo(){
		if (lazy!=1e9){
			if (s==e) val={lazy,-1e9};
			else val={lazy,lazy};
			
			if (s!=e){
				l->lazy=lazy;
				r->lazy=lazy;
			}
			
			lazy=1e9;
		}
	}
	
	ii merge(ii i,ii j){
		vector<int> v={i.fi,i.se,j.fi,j.se};
		sort(all(v));
		return {v[3],v[2]};
	}
	
	void update(int i,int j,int k){
		propo();
		if (s==i && e==j){
			lazy=k;
		}
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=merge(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		propo();
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return merge(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

int n,q;

struct Q{
	int t;
	int a,b,c;
	int idx;
};

vector<Q> qu;

set<int> s;
int sick[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	
	int a,b,c;
	rep(x,0,q){
		cin>>a;
		
		if (a==0){
			cin>>a>>b>>c;
			qu.pub({0,a,b,c,x});
		}
		else{
			cin>>a;
			qu.pub({1,a,-1,-1,x});
		}
	}
	
	reverse(all(qu));
	
	for (auto &it:qu){
		if (it.t==0 && it.c==0){
			root->update(it.a,it.b,it.idx);
		}
	}
	
	rep(x,1,n+1) if (root->query(x,x)==ii(1e9,-1e9)) s.insert(x);
	memset(sick,63,sizeof(sick));
	
	//rep(x,1,n+1) cout<<root->query(x,x).fi<<" "; cout<<endl;
	// cout<<root->query(1,2).fi<<" "<<root->query(1,2).se<<endl;
	// cout<<root->query(2,3).fi<<" "<<root->query(2,3).se<<endl;
	
	for (auto &it:qu){
		if (it.t==0 && it.c==1){
			auto temp=root->query(it.a,it.b);
			//cout<<it.a<<" "<<it.b<<" "<<temp.fi<<" "<<temp.se<<endl;
			if (temp.se!=1e9){
				int pos=*s.lb(it.a);
				sick[pos]=min(sick[pos],max(it.idx,temp.se));
			}
		}
	}
	
	//rep(x,1,n+1) cout<<sick[x]<<" "; cout<<endl;
	
	reverse(all(qu));
	
	for (auto &it:qu) if (it.t==1){
		if (root->query(it.a,it.a).fi<=it.idx) cout<<"NO"<<endl;
		else if (sick[it.a]<=it.idx) cout<<"YES"<<endl;
		else cout<<"N/A"<<endl;
		
		//rep(x,1,n+1) cout<<root->query(x,x).fi<<" "; cout<<endl;
	}
}