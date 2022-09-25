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
int arr[200005];

int memo[200005];

bool can(int i){
	int len=0;
	
	rep(x,0,n){
		memo[x]=0;
	
		if (arr[x]<=i){
			memo[x]=1+(x!=0);
			if (2<=x) memo[x]=max(memo[x],memo[x-2]+2);
		}
		if (x) memo[x]=max(memo[x],memo[x-1]);
		
		len=max(len,memo[x]+(x!=n-1));	
	}
	
	return k<=len;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	int lo=0,hi=1e9+5,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (!can(mi)) lo=mi;
		else hi=mi;
	}
	
	cout<<hi<<endl;
}