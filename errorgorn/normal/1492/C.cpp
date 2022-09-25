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

int n,m;
string s;
string t;

vector<int> pos1;
vector<int> pos2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	cin>>s;
	cin>>t;
	
	rep(x,0,n){
		if (s[x]==t[sz(pos1)]){
			pos1.pub(x);
			if (sz(pos1)==m) break;
		}
	}
	
	rep(x,n,0){
		if (s[x]==t[m-1-sz(pos2)]){
			pos2.pub(x);
			if (sz(pos2)==m) break;
		}
	}
	
	reverse(all(pos2));
	
	int ans=0;
	rep(x,0,m-1) ans=max(ans,pos2[x+1]-pos1[x]);
	
	cout<<ans<<endl;
}