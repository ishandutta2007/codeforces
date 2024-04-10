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

int n,k;
string s;
set<int> taken;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		taken.clear();
		
		cin>>n>>k;
		cin>>s;
		
		deque<int> v;
		rep(x,0,n){
			if (s[x]=='0') v.push_back(x);
			if (!v.empty() && v[0]==x-k) v.pop_front();
			
			if (x<k-1 || !v.empty() && x-v[0]>20) continue;
			int val=0;
			for (auto &it:v){
				val|=1<<(x-it);
			}
			taken.insert(val);
		}
		
		rep(x,0,1<<min(20,k)){
			if (!taken.count(x)){
				cout<<"YES"<<endl;
				string ans;
				rep(y,0,k){
					if (x&1) ans+='1';
					else ans+='0';
					x/=2;
				}
				reverse(all(ans));
				cout<<ans<<endl;
				goto done;
			}
		}
		
		cout<<"NO"<<endl;
		done:;
	}
}