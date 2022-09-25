//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

struct UFDS{
	int p[200005];
	
	UFDS(){
		rep(x,0,200005) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	bool unions(int i,int j){
		i=par(i),j=par(j);
		if (i==j) return false;
		p[j]=i;
		return true;
	}
} ufds,ufds2;

ll n,m;
vector<iii> edges;
int deg[200005];

set<int> al[200005];

int cnt=0;

set<int> alive;

void dfs(int i){
	alive.erase(i);
	int curr=0;
	
	while (true){
		auto it=alive.ub(curr);
		if (it==alive.end()) break;
		
		curr=*it;
		if (!al[i].count(curr)){
			dfs(curr);
			cnt++;
			ufds.unions(i,curr);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	rep(x,0,m){
		int a,b,c;
		cin>>a>>b>>c;
		edges.pub(iii(ii(a,b),c));
		deg[a]++,deg[b]++;
		al[a].insert(b);
		al[b].insert(a);
	}
	
	rep(x,1,n+1) alive.insert(x);
	
	rep(x,1,n+1) if (alive.count(x)) dfs(x);
	
	ll mn=0;
	for (auto &it:edges) mn^=it.se;
	
	sort(all(edges),[](iii i,iii j){
		return i.se<j.se;
	});
	
	ll ans=0;
	for (auto &it:edges){
		if (ufds.unions(it.fi.fi,it.fi.se)){
			ufds2.unions(it.fi.fi,it.fi.se);
			ans+=it.se;
		}
		else{
			if (ufds2.par(it.fi.fi)!=ufds2.par(it.fi.se)) mn=min(mn,it.se);
		}
	}
	
	if (n*(n-1)/2-m!=cnt) cout<<ans<<endl;
	else cout<<ans+mn<<endl;
}