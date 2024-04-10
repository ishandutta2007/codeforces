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
int arr[200005];
int brr[200005];
 
vector<int> al[200005];
bool onstk[200005];
bool vis[200005];
 
bool cyc;
void dfs(int i){
	onstk[i]=vis[i]=true;
	
	for (auto it:al[i]){
		if (onstk[it]) cyc=true;
		if (!vis[it]) dfs(it);
	}
	
	onstk[i]=false;
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
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) vis[x]=onstk[x]=false;
		
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		
		rep(x,1,n+1) al[arr[x]].pub(brr[x]);
		
		int mx=1;
		rep(x,1,n+1) if (sz(al[x])>sz(al[mx])) mx=x;
		
		vis[mx]=true;
		cyc=false;
		rep(x,1,n+1) if (!vis[x]) dfs(x);
		
		if (cyc) cout<<"WA"<<endl;
		else cout<<"AC"<<endl;
	}
}