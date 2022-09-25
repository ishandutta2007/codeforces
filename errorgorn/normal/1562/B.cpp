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

string s;
bool check(string t){
	int idx=0;
	rep(x,0,sz(s)){
		if (s[x]==t[idx]){
			idx++;
			if (idx==sz(t)) return true;
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		cin>>s;
		
		vector<string> v={
			"1",
			"4",
			"6",
			"8",
			"9",
			"22",
			"25",
			"27",
			"32",
			"33",
			"35",
			"52",
			"55",
			"57",
			"72",
			"75",
			"77"
		};
		
		for (auto &it:v){
			if (check(it)){
				cout<<sz(it)<<endl;
				cout<<it<<endl;
				break;
			}
		}
	}
}