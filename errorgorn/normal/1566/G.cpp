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
#define ii pair<int,int>
#define iii pair<int,ii>
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

int n,m,q;
map<ii,int> ma;
multiset<int> best;
set<ii> al[100005];
set<iii> imp;

ii fix(int i,int j){
	if (i<j) return {i,j};
	else return {j,i};
}

bool top(int i,int j,int k){
	int cnt=0;
	for (auto [a,b]:al[i]){
		if (a==j && b==k) return true;
		if ((++cnt)==3) break;
	}
	return false;
}

void rem(int i){ //effectively removes the node from the graph
	int cnt=0;
	int tot=0;
	for (auto [a,b]:al[i]){
		if (top(b,a,i)) imp.erase(iii(a,fix(b,i)));
		tot+=a;
		if ((++cnt)==3) break;
	}
	if (cnt==3) best.erase(best.find(tot));
}

void add(int i){
	int cnt=0;
	int tot=0;
	for (auto [a,b]:al[i]){
		if (top(b,a,i)) imp.insert(iii(a,fix(b,i)));
		tot+=a;
		if ((++cnt)==3) break;
	}
	if (cnt==3) best.insert(tot);
}

bool ok(int a,int b,int c,int d){
	return a!=c && a!=d && b!=c && b!=d;
}

int ans(){
	auto temp=(*imp.begin()).se;
	int res=1e18;
	
	vector<iii> v;
	for (auto it:imp){
		v.pub(it);
		if (ok(temp.fi,temp.se,it.se.fi,it.se.se)) break;
	}
	
	rep(x,0,sz(v)) rep(y,0,sz(v)){
		if (ok(v[x].se.fi,v[x].se.se,v[y].se.fi,v[y].se.se)){
			res=min(res,v[x].fi+v[y].fi);
		}
	}
	
	return min(res,(best.empty()?(int)1e18:*best.begin()));
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		if (a>b) swap(a,b);
		
		rem(a),rem(b);
		ma[ii(a,b)]=c;
		al[a].insert({c,b});
		al[b].insert({c,a});
		add(a),add(b);
	}
	
	cout<<ans()<<endl;
	
	int t;
	cin>>q;
	rep(x,0,q){
		cin>>t;
		
		cin>>a>>b;
		if (a>b) swap(a,b);
		
		rem(a),rem(b);
		if (t==1){
			cin>>c;
			ma[ii(a,b)]=c;
			al[a].insert({c,b});
			al[b].insert({c,a});
		}
		else{
			int c=ma[ii(a,b)];
			al[a].erase({c,b});
			al[b].erase({c,a});
		}
		add(a),add(b);
		
		cout<<ans()<<endl;
	}
}