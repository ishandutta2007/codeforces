#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

const ll INF=1e18;

int n,m;
ll arr[105][105];
ll w[105][105];

inline ll test(ll i){
	rep(x,1,n+1) rep(y,1,m+1){
		if (arr[x][y]<i) w[x][y]=INF;
		else w[x][y]=min(w[x-1][y],w[x][y-1])+arr[x][y]-i;
	}
	
	return w[n][m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(w,63,sizeof(w));
	w[0][1]=0;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		
		rep(x,1,n+1) rep(y,1,m+1){
			cin>>arr[x][y];
			
			arr[x][y]-=x+y;
		}
		
		ll ans=INF;
		
		rep(x,1,n+1) rep(y,1,m+1) ans=min(ans,test(arr[x][y]));
		
		cout<<ans<<endl;
	}
}