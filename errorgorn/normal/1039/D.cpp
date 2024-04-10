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

int n;
vector<int> al2[100005];

vector<int> topo;
vector<int> al[100005];

void dfs(int i,int p){
	for (auto &it:al2[i]){
		if (it==p) continue;
		al[i].pub(it);
		dfs(it,i);
	}
	topo.pub(i);
}

ii memo[100005];
int solve(int k){
	memset(memo,0,sizeof(memo));
	
	for (auto &it:topo){
		ll res=0;
		ii mx={0,0};
		
		for (auto &it2:al[it]){
			res+=memo[it2].fi;
			if (mx.fi<memo[it2].se) mx={memo[it2].se,mx.fi};
			else if (mx.se<memo[it2].se) mx.se=memo[it2].se;
		}
		
		mx.fi++;
		if (mx.fi+mx.se>=k) memo[it]={res+1,0};
		else memo[it]={res,mx.fi};
	}
	
	return memo[1].fi;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al2[a].pub(b);
		al2[b].pub(a);
	}
	
	dfs(1,-1);
	
	int curr=1;
	while (curr<=n){
		int ans=solve(curr);
		if (curr<=400){
			cout<<ans<<endl;
			curr++;
			continue;
		}
		
		int lo=curr,hi=n+1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (solve(mi)==ans) lo=mi;
			else hi=mi;
		}
		
		rep(x,curr,lo+1) cout<<ans<<endl;
		curr=hi;
	}
}