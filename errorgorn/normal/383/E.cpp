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
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int memo[16800000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	string s;
	rep(x,0,n){
		cin>>s;
		
		vector<int> v={s[0]-'a',s[1]-'a',s[2]-'a'};
		sort(all(v));
		v.erase(unique(all(v)),v.end());
		for (auto &it:v) it=(1<<it);
		
		memo[v[0]]++;
		if (sz(v)>=2){
			memo[v[1]]++;
			memo[v[0]|v[1]]--;
		}
		if (sz(v)>=3){
			memo[v[2]]++;
			memo[v[0]|v[2]]--;
			memo[v[1]|v[2]]--;
			memo[v[0]|v[1]|v[2]]++;
		}
	}
	
	rep(bit,0,24){
		rep(x,0,1<<24){
			if (x&(1<<bit)) memo[x]+=memo[x^(1<<bit)];
		}
	}
	
	int ans=0;
	rep(x,0,1<<24) ans^=memo[x]*memo[x];
	
	cout<<ans<<endl;
}