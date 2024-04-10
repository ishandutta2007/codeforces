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

int n,k;
int arr[100005];
vector<int> al[100005];

int tot,cnt;

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		arr[i]^=arr[it];
	}
	
	if (i!=1 && arr[i]==tot){
		arr[i]=0;
		cnt++;
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
		cin>>n>>k;
		
		rep(x,1,n+1) al[x].clear();
		
		rep(x,1,n+1) cin>>arr[x];
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			
			al[a].pub(b);
			al[b].pub(a);
		}
		
		tot=0;
		rep(x,1,n+1) tot^=arr[x];
		
		if (tot==0){
			cout<<"YES"<<endl;
			continue;
		}
		
		cnt=0;
		dfs(1,-1);
		
		if (cnt>=2 && k>=3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}