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

int n,m;
int arr[200005];
int brr[200005];
vector<int> al[200005];

bool bip;
bool vis[200005];
bool col[200005];

void dfs(int i){
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (!vis[it]){
			col[it]=!col[i];
			dfs(it);
		}
		else if (col[it]==col[i]){
			bip=false;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		bip=true;
		rep(x,1,n+1) vis[x]=false;
		rep(x,1,n+1) al[x].clear();
		
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		dfs(1);
		
		rep(x,1,n+1) if (col[x]){
			arr[x]=-arr[x];
			brr[x]=-brr[x];
		}
		
		ll tot1=0,tot2=0;
		rep(x,1,n+1){
			tot1+=arr[x];
			tot2+=brr[x];
		}
		
		if (bip){
			if (tot1==tot2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			if (abs(tot1)%2==abs(tot2)%2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}