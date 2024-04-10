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

const int MOD=1000000007;

ll arr[2000005];
ll brr[2000005];
ll crr[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	arr[2]=1;
	rep(x,3,2000005){
		brr[x]=arr[x-1];
		arr[x]=(arr[x-1]+2*brr[x-1])%MOD;
		crr[x]=(brr[x]+crr[x-3])%MOD;
		
		//if (x<100) cout<<x<<" "<<arr[x]<<" "<<brr[x]<<" "<<crr[x]<<endl;
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		cout<<(crr[n]*4)%MOD<<endl;
	}
}