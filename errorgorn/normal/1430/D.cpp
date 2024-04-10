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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
string s;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		v.clear();
	
		cin>>n;
		cin>>s;
		
		int cnt=1;
		rep(x,1,n){
			if (s[x-1]!=s[x]){
				v.push_back(cnt);
				cnt=1;
			}
			else{
				cnt++;
			}
		}
		v.push_back(cnt);
		
		//for (auto &it:v) cout<<it<<" "; cout<<endl;
		
		reverse(all(v));
		
		int idx=sz(v);
		
		int ans=0;
		while (!v.empty()){
			if (idx==sz(v)) idx--;
			while (idx!=-1 && v[idx]==1) idx--;
			if (idx!=-1){
				v[idx]--;
				v.pop_back();
				ans++;
			}
			else{
				v.pop_back();
				if (!v.empty()) v.pop_back();
				ans++;
			}
		}
		
		cout<<ans<<endl;
	}
}