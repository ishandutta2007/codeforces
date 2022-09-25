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

const int INF=1e9;

struct node{
	int s,e,m;
	int val=-INF,lazy=0;
	node *l=nullptr,*r=nullptr;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val+=lazy;
			
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
			val=max(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		propo();
	
		if (s==i && e==j) return val;
		else if (l==nullptr) return -1e9;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root[2]={new node(0,400005),new node(0,400005)};

int n;
vector<iii> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	vector<int> uni={0};
	
	int a,b,c;
	rep(x,0,n){
		cin>>a>>b>>c;
		
		v.push_back(iii(ii(b,a),c-1));
		uni.push_back(a);
		uni.push_back(b);
	}
	
	sort(all(uni));
	uni.erase(unique(all(uni)),uni.end());
	
	map<int,int> id;
	rep(x,0,sz(uni)) id[uni[x]]=x;
	
	rep(x,0,n){
		v[x].fi.fi=id[v[x].fi.fi];
		v[x].fi.se=id[v[x].fi.se];
	}
	
	root[0]->update(0,0,INF);
	root[1]->update(0,0,INF);
	
	sort(all(v));
	reverse(all(v));
	
	while (!v.empty()){
		int curr=v.back().fi.fi;
		
		while (!v.empty() && v.back().fi.fi==curr){
			int l=v.back().fi.se,r=v.back().fi.fi,idx=v.back().se;
			v.pop_back();
			
			root[idx]->update(0,l-1,1);
		}
		
		int temp=max(root[0]->query(0,curr-1),root[1]->query(0,curr-1));
		root[0]->update(curr,curr,temp+INF);
		root[1]->update(curr,curr,temp+INF);
	}
	
	cout<<max(root[0]->val,root[1]->val)<<endl;
}