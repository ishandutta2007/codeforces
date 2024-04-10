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

int n;
ii arr[100005];
vector<int> v1,v2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	ll gcd=0;
	rep(x,n,0){
		arr[x].fi-=arr[0].fi,arr[x].se-=arr[0].se;
		gcd=__gcd(gcd,__gcd(arr[x].fi,arr[x].se));
	}
	
	rep(x,0,n){
		arr[x].fi=abs(arr[x].fi/gcd);
		arr[x].se=abs(arr[x].se/gcd);
		
		if (arr[x].fi%2==1 && arr[x].se%2==1){
			v2.push_back(x);
		}
		else if (arr[x].fi%2==1 || arr[x].se%2==1){
			v1.push_back(x);
		}
	}
	
	
	if (v1.empty()) swap(v1,v2);
	
	cout<<sz(v1)<<endl;
	for (auto &it:v1) cout<<it+1<<endl;
	
}