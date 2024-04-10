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
int pos[100005];
int nxt[100005];
bool vis[100005];

int num=0;
void dfs(int i){
	num++;
	vis[i]=true;
	if (!vis[nxt[i]]) dfs(nxt[i]);
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
		
		rep(x,1,n+1) vis[x]=false;
		
		int a;
		rep(x,1,n+1){
			cin>>a;
			pos[a]=x;
		}
		rep(x,1,n+1){
			cin>>a;
			nxt[x]=pos[a];
		}
		
		int waste=0;
		rep(x,1,n+1) if (!vis[x]){
			num=0;
			dfs(x);
			waste+=num%2;
		}
		
		int ans=0;
		for (int x=n;x>waste;x-=2){
			ans+=2*(x-1);
		}
		
		cout<<ans<<endl;
	}
}