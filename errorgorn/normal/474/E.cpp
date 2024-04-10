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
#define ii pair<int,int>
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

const ll L=-1e10,H=1e15+1e10;

struct node{
	ii val=ii(0,-1);
	node *l=nullptr,*r;
	
	node (){}
	
	void make(){
		if (l==nullptr){
			l=new node();
			r=new node();
		}
	}
	
	void update(ll i,ii j,ll s=L,ll e=H){
		ll m=s+e>>1;
		val=max(val,j);
		
		if (s==e) return;
		else{
			make();
			if (i<=m) l->update(i,j,s,m);
			else r->update(i,j,m+1,e);
		}
	}
	
	ii query(ll i,ll j,ll s=L,ll e=H){
		ll m=s+e>>1;
		if (s==i && e==j) return val;
		else{
			if (l==nullptr) return ii(0,-1);
			if (j<=m) return l->query(i,j,s,m);
			else if (m<i) return r->query(i,j,m+1,e);
			else return max(l->query(i,m,s,m),r->query(m+1,j,m+1,e));
		}
	}
} *root=new node();

ll n,d;
ll arr[100005];
int p[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>d;
	rep(x,0,n) cin>>arr[x];
	
	int best=-1;
	int idx=-1;
	rep(x,0,n){
		auto temp=max(root->query(L,arr[x]-d),root->query(arr[x]+d,H));
		p[x]=temp.se;
		temp.fi++;
		if (temp.fi>best){
			best=temp.fi;
			idx=x;
		}
		root->update(arr[x],ii(temp.fi,x));
	}
	
	cout<<best<<endl;
	
	vector<int> ans;
	rep(x,0,best){
		ans.push_back(idx);
		idx=p[idx];
	}
	reverse(all(ans));
	for (auto &it:ans) cout<<it+1<<" "; cout<<endl;
}