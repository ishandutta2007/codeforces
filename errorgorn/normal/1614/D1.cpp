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
#define ii pair<int,int>
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
int arr[100005];
ll cnt[20000005];

ll memo[20000005];

bool comp[20000005];
vector<ll> primes;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int lim=20000003;
	rep(x,2LL,lim) if (!comp[x]){
		primes.pub(x);
		
		for (ll y=x*x;y<lim;y+=x){
			comp[y]=true;
		}
	}
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) cnt[arr[x]]++;
	
	for (auto &it:primes){
		for (int x=lim/it;x;x--){
			cnt[x]+=cnt[x*it];
		}
	}
	
	rep(x,1,lim){
		for (auto &it:primes){
			if (it*x>lim) break;
			memo[it*x]=max(memo[it*x],memo[x]+x*(cnt[x]-cnt[it*x]));
		}
	}
	
	ll ans=0;
	rep(x,0,lim){
		ans=max(ans,memo[x]+cnt[x]*x);
	}
	
	cout<<ans<<endl;
}