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

int n;
ll arr[100005];
ll brr[100005];
vector<int> al[100005];

struct line{
	ll m,c;
	
	ll eval(ll x){
		return m*x+c;
	}
};
vector<line> lines[100005];
ll ans[100005];

struct node{
	int s,e,m;
	line val=line({0,(ll)1e18});
	node *l=nullptr,*r=nullptr;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
	}
	
	void update(line i){
		if (val.eval(m)>i.eval(m)) swap(val,i);
		
		if (i.c==1e18 || s+1==e) return;
		
		if (i.eval(s)<val.eval(s)){
			if (l==nullptr) l=new node(s,m);
			l->update(i);
		}
		else if (i.eval(e)<val.eval(e)){
			if (r==nullptr) r=new node(m,e);
			r->update(i);
		}
	}
	
	ll query(int i){
		if (s+1==e) return val.eval(i);
		else if (i<=m){
			if (l==nullptr) return val.eval(i);
			else return min(val.eval(i),l->query(i));
		}
		else{
			if (r==nullptr) return val.eval(i);
			else return min(val.eval(i),r->query(i));
		}
	}
} *root[100005];

void dfs(int i,int p){
	root[i]=new node(-100005,100005);
	
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs(it,i);
		
		if (sz(lines[it])>sz(lines[i])){
			swap(lines[it],lines[i]);
			swap(root[it],root[i]);
		}
		for (auto &it:lines[it]){
			lines[i].pub(it);
			root[i]->update(it);
		}
	}
	
	ll val=root[i]->query(arr[i]);
	
	if (val==1e18) val=0;
	ans[i]=val;
	
	lines[i].pub({brr[i],val});
	root[i]->update({brr[i],val});
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) cin>>brr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	rep(x,1,n+1) cout<<ans[x]<<" ";
}