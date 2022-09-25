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
int ans[200005];

vector<ii> idx;

vector<ii> ranges;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,n,0){
		vector<ii> temp={ {arr[x],x} };
		
		for (auto it:idx){
			if (__gcd(temp.back().fi,it.fi)!=temp.back().fi){
				temp.pub({__gcd(temp.back().fi,it.fi),it.se});
			}
		}
		
		idx=temp;
		
		rep(y,0,sz(idx)){
			int l,r;
			l=idx[y].se;
			if (y==sz(idx)-1) r=n-1;
			else r=idx[y+1].se-1;
			
			if (l<=x+idx[y].fi-1 && x+idx[y].fi-1<=r){
				ranges.pub({x,x+idx[y].fi-1});
			}
		}
	}
	
	sort(all(ranges),[](ii i,ii j){
		return i.se<j.se;
	});
	
	int pp=-1;
	for (auto it:ranges){
		if (pp<it.fi){
			ans[it.se]++;
			pp=it.se;
		}
	}
	
	rep(x,1,n) ans[x]+=ans[x-1];
	
	rep(x,0,n) cout<<ans[x]<<" "; cout<<endl;
}