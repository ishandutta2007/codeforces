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
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m;
	int val=0,lazy=-1;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy!=-1){
			val=lazy*(e-s+1);
			if (s!=e){
				l->lazy=lazy;
				r->lazy=lazy;
			}
			lazy=-1;
		}
	}
	
	void update(int i,int j,int k){  
		propo();
		
		if (s==i && e==j) lazy=k;
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
} *root;

ll n,q;
string s,t;
vector<ii> ranges;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		ranges.clear();
		
		cin>>n>>q;
		cin>>s;
		cin>>t;
		
		int a,b;
		rep(x,0,q){
			cin>>a>>b;
			a--,b--;
			ranges.pub(ii(a,b));
		}
		
		reverse(all(ranges));
		
		root=new node(0,n-1);
		
		rep(x,0,n) if (t[x]=='1') root->update(x,x,1);
		
		for (auto &it:ranges){
			//cerr<<it.fi<<" "<<it.se<<endl;
			int cnt=root->query(it.fi,it.se);
			
			int len=it.se-it.fi+1;
			//cerr<<it.fi<<" "<<it.se<<endl;
			
			if (cnt<(len+1)/2){
				root->update(it.fi,it.se,0);
			}
			else if (len-cnt<(len+1)/2){
				root->update(it.fi,it.se,1);
			}
			else{
				cout<<"NO"<<endl;
				goto done;
			}
		}
		
		//cerr<<"lol"<<endl;
		rep(x,0,n){
			if ((s[x]&1)!=root->query(x,x)){
				cout<<"NO"<<endl;
				goto done;
			}
		}
		
		cout<<"YES"<<endl;
		done:;
	}
}