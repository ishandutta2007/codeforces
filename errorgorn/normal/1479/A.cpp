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
#define debug(x) cout << #x << " is " << x << endl

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
int memo[100005];

int ask(int i){
	if (i==0 || i==n+1) return 1e9;
	if (memo[i]) return memo[i];
	
	cout<<"? "<<i<<endl;
	int temp;
	cin>>temp;
	return memo[i]=temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int lo=1,hi=n,mi;
	
	while (hi-lo>20){
		mi=hi+lo>>1;
		
		if (ask(mi)<ask(mi+1)) hi=mi;
		else lo=mi+1;
	}
	
	rep(x,lo,hi+1) if (ask(x)<min(ask(x+1),ask(x-1))){
		cout<<"! "<<x<<endl;
		return 0;
	}
}