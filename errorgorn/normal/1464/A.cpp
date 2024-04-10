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

int n,k;
vector<int> al[100005];
bool vis[100005];

int sz;
bool dfs(int i,int p,int head){
	vis[i]=true;
	sz++;
	for (auto &it:al[i]){
		if (it==p){
			p=-1;
			continue;
		}
		if (it==head) return true;
		if (dfs(it,i,head)) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		
		rep(x,1,n+1) al[x].clear(),vis[x]=false;
		
		int a,b;
		rep(x,0,k){
			cin>>a>>b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		
		int ans=0;
		rep(x,1,n+1) if (!vis[x]){
			sz=0;
			if (dfs(x,-1,x)){
				if (sz!=1) ans+=sz+1;
			}
			else{
				if (sz!=1) ans+=sz-1;
			}
		}
		
		cout<<ans<<endl;
	}
	
}