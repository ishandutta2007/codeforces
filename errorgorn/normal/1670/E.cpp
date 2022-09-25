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

int n;
vector<ii> al[140000];

int ans1[140000];
int ans2[140000];
int IDX;

void dfs(int i,int p,int par){
	for (auto [it,idx]:al[i]){
		if (it==p) continue;
		
		ans1[it]=IDX;
		ans2[idx]=IDX+(1<<n);
		IDX++;
		if (par) swap(ans1[it],ans2[idx]);
		
		dfs(it,i,par^1);
	}
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
		
		rep(x,1,(1<<n)+1) al[x].clear();
		
		int a,b;
		rep(x,1,1<<n){
			cin>>a>>b;
			al[a].pub({b,x});
			al[b].pub({a,x});
		}
		
		IDX=1;
		ans1[1]=1<<n;
		dfs(1,-1,0);
		
		cout<<1<<endl;
		rep(x,1,(1<<n)+1) cout<<ans1[x]<<" "; cout<<endl;
		rep(x,1,1<<n) cout<<ans2[x]<<" "; cout<<endl;
	}
}