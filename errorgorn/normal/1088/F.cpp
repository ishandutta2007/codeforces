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

int n;
ll arr[500005];
vector<int> al[500005];

int tk[20][500005];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		int curr=tk[0][it]=i;
		rep(x,0,20){
			if (curr==-1) break;
			curr=tk[x+1][it]=tk[x][curr];
		}
		dfs(it,i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		a--,b--;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	int mn=0;
	rep(x,1,n) if (arr[x]<arr[mn]) mn=x;
	
	memset(tk,-1,sizeof(tk));
	dfs(mn,-1);
	
	ll ans=0;
	rep(x,0,n) if (x!=mn){
		ll best=arr[tk[0][x]];
		int curr=tk[0][x];
		
		rep(x,0,20){
			curr=tk[x][curr];
			if (curr==-1){
				best=min(best,arr[mn]*(x+2));
				break;
			}
			best=min(best,arr[curr]*(x+2));
		}
		//cout<<x<<" "<<best<<" "<<arr[x]<<endl;
		ans+=best+arr[x];
	}
	
	cout<<ans<<endl;
}