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

int n,k;
int arr[100005];
ii range[100005];

ii inter(ii a,ii b){
	return {max(a.fi,b.fi),min(a.se,b.se)};
}

bool l(int i){
	ii range=ii(0,0);
	rep(x,1,n+1){
		range=inter({range.fi+i,1e9},{arr[x],arr[x+1]});
		if (range.se<range.fi) return false;
	}
	return range.se==arr[n+1];
}

bool r(int i){
	ii range=ii(0,0);
	rep(x,1,n+1){
		range=inter({0,range.se+i},{arr[x],arr[x+1]});
		if (range.se<range.fi) return false;
	}
	return range.se==arr[n+1];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>k>>n;
	
	arr[0]=0;
	rep(x,1,n+1) cin>>arr[x];
	arr[n+1]=k;
	
	int lo,hi,mi;
	
	lo=-1,hi=1e9+5;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (l(mi)) lo=mi;
		else hi=mi;
	}
	int l=lo;
	
	lo=-1,hi=1e9+5;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (r(mi)) hi=mi;
		else lo=mi;
	}
	int r=hi;
	
	range[0]={0,0};
	rep(x,1,n+1){
		range[x]=inter({range[x-1].fi+l,range[x-1].se+r},{arr[x],arr[x+1]});
	}
	
	vector<int> ans={arr[n+1]};
	rep(x,n,0){
		auto temp=inter({ans.back()-r,ans.back()-l},range[x]);
		ans.pub(temp.se);	
	}
	
	reverse(all(ans));
	
	rep(x,0,n){
		cout<<ans[x]<<" "<<ans[x+1]<<endl;
	}
}