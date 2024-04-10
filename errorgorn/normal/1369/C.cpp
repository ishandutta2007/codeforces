/*













*/

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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
deque<int> dq;
vector<int> w;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		w.clear();
		
		cin>>n>>k;
		
		int t;
		rep(x,0,n){
			cin>>t;
			dq.push_back(t);
		}
		sort(all(dq));
		
		ll ans=0;
		
		rep(x,0,k){
			cin>>t;
			if (t==1){
				ans+=dq.back()*2;
				dq.pop_back();
			}
			else w.push_back(t);
		}
		
		sort(all(w));
		reverse(all(w));
		
		for (auto &it:w){
			ans+=dq.back()+dq.front();
			dq.pop_back(),dq.pop_front();
			
			rep(x,0,it-2) dq.pop_front();
		}
		
		cout<<ans<<endl;
	}
}