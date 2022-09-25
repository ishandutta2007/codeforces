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

const int MOD=998244353;

int n,m;
int arr[200005];
int brr[200005];
vector<int> v;

ll ans=1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,m) cin>>brr[x];
	
	v.push_back(n-1);
	rep(x,n,0){
		if (arr[v.back()]>arr[x]) v.push_back(x);
	}
	
	reverse(all(v));
	
	if (arr[v[0]]!=brr[0]){
		cout<<"0"<<endl;
		return 0;
	}
	
	int idx=1;
	rep(x,1,sz(v)){
		//cout<<arr[v[x]]<<endl;
		if (arr[v[x]]==brr[idx]){
			ans=ans*(v[x]-v[x-1])%MOD;
			idx++;
		}
	}
	
	if (idx!=m){
		cout<<"0"<<endl;
		return 0;
	}
	
	cout<<ans<<endl;
	
}