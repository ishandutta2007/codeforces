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

const int MOD=998244353;

int n;
int arr[100005];

#define num fi.fi
#define val fi.se
#define cnt se

vector<iii> v;

vector<iii> temp;

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
		rep(x,0,n) cin>>arr[x];
		
		reverse(arr,arr+n);
		
		ll ans=0;
		int mx=0;
		rep(x,0,n){
			temp.clear();
			
			for (auto it:v){
				ll mul=(arr[x]+it.num-1)/it.num;
				if (it.num*it.num<=arr[x]){
					if (arr[x]%it.num==0)
						temp.pub(iii(ii(it.num,(it.val+it.cnt*(mul-1))%MOD),it.cnt));
					else
						temp.pub(iii(ii(it.num-1,(it.val+it.cnt*(mul-1))%MOD),it.cnt));
				}
				else{
					temp.pub(iii(ii(arr[x]/mul,(it.val+it.cnt*(mul-1))%MOD),it.cnt));
				}
			}
			
			temp.pub(iii(ii(arr[x],0),1));
			
			sort(all(temp),[](iii i,iii j){
				return i.num<j.num;
			});
			
			v.clear();
			for (auto it:temp){
				ans=(ans+it.val)%MOD;
				if (!v.empty() && v.back().num==it.num){
					v.back().val=(v.back().val+it.val)%MOD;
					v.back().cnt=(v.back().cnt+it.cnt)%MOD;
				}
				else{
					v.pub(it);
				}
			}
		}
		
		cout<<ans<<endl;
	}
}