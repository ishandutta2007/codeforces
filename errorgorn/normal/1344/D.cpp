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

ll n,k;
int arr[100005];
int ans[100005];

ll sq(ll x){return x*x;}

ll test(ll delta){
	ll res=0;
	
	rep(x,0,n){
		ll lo=0,hi=arr[x]+1,mi;
		
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if ((mi+1)*(arr[x]-sq(mi+1))-mi*(arr[x]-sq(mi))>=delta) lo=mi;
			else hi=mi;
		}
		
		res+=lo;
		ans[x]=lo;
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	ll lo=-5*1e18,hi=1e9,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (test(mi)>=k) lo=mi;
		else hi=mi;		
	}
	
	ll curr=test(lo);
	
	rep(x,0,n){
		if (curr>k && (ans[x]+1)*(arr[x]-sq(ans[x]+1))-(ans[x])*(arr[x]-sq(ans[x]))==lo){
			curr--;
			ans[x]--;
		}
		cout<<ans[x]<<" ";
	}	
}