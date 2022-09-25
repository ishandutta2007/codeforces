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

int n;
int arr[200005];
vector<int> pos[200005];

vector<ii> ranges;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) pos[arr[x]].pub(x);
	
	vector<int> idx;
	rep(x,1,n+1) if (pos[arr[x]].front()==x) idx.pub(arr[x]);
	
	int ans=0;
	
	int mx=-1;
	for (auto it:idx){
		if (mx<pos[it].back()){
			if (sz(pos[it])==1) continue;
			
			ans+=sz(pos[it]);
			ranges.pub({pos[it].front(),pos[it].back()});
			mx=pos[it].back();
		}
		else{
			ans+=sz(pos[it]);
		}
	}
	
	int pos=0;
	while (pos<sz(ranges)){
		ans-=2;
		if (pos==sz(ranges)-1 || ranges[pos].se<ranges[pos+1].fi){
			pos++;
			continue;
		}
		
		int r=pos+1;
		while (r!=sz(ranges)-1 && ranges[r+1].fi<ranges[pos].se) r++;
		pos=r;
		ans++;
	}
	
	cout<<ans<<endl;
}