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

ll n,a,r,m;
ll arr[100005];

ll test(int i){
	ll add=0,rmv=0;
	
	rep(x,0,n){
		if (arr[x]<i) add+=i-arr[x];
		else rmv+=arr[x]-i;
	}
	
	ll move=min(add,rmv);
	add-=move,rmv-=move;
	
	return add*a+rmv*r+move*m;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>a>>r>>m;
	m=min(m,a+r);
	rep(x,0,n) cin>>arr[x];
	
	int l=0,r=1e9;
	
	while (r-l>10){
		int t1=l+(r-l)/3,t2=l+(r-l)*2/3;
		ll v1=test(t1),v2=test(t2);
		
		if (v1>v2) l=t1;
		else r=t2;
	}
	
	ll ans=1e18;
	rep(x,l,r+1){
		ans=min(ans,test(x));
	}
	
	cout<<ans<<endl;
}