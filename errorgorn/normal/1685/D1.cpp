//
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

struct UFDS{
	int p[205];
	
	void reset(){
		rep(x,0,205) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	bool unions(int i,int j){
		i=par(i),j=par(j);
		if (i==j) return false;
		p[i]=j;
		return true;
	}
} ufds;

int n;
int arr[205];
int brr[205];

vector<int> al[205];
int vis[205];
vector<int> ans;

void dfs(int i){
	ans.pub(i);
	vis[i]=2;
	
	int curr=arr[i];
	while (vis[curr]==0){
		vis[curr]=1;
		curr=arr[curr];
	}
	
	for (auto it:al[i]) if (vis[it]==0) dfs(it);
	
	if (vis[brr[i]]!=2) dfs(brr[i]);
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
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) brr[arr[x]]=x;
		
		ufds.reset();
		
		rep(x,1,n+1) ufds.unions(x,arr[x]);
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n) if (ufds.unions(x,x+1)){
			al[x].pub(brr[x+1]);
			al[x+1].pub(brr[x]);
			
			// cout<<"debug: "<<endl;
			// cout<<x<<" "<<brr[x+1]<<endl;
			// cout<<x+1<<" "<<brr[x]<<endl;
		}
		
		memset(vis,0,sizeof(vis));
		
		ans.clear();
		dfs(1);
		
		for (auto it:ans) cout<<it<<" "; cout<<endl;
	}
}