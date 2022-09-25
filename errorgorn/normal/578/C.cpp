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

int n;
long double arr[200005];

long double val(long double i){
	long double mn=0,mx=0;
	long double curr=0;
	
	long double res=0;
	
	rep(x,0,n){
		curr+=arr[x]-i;
		
		res=max(res,max(curr-mn,mx-curr));
		mx=max(mx,curr);
		mn=min(mn,curr);
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	long double lo=-10000,hi=10000,mi1,mi2;
	
	while (hi-lo>1e-12){
		mi1=lo+(hi-lo)/3;
		mi2=lo+(hi-lo)/3*2;
		
		if (val(mi1)<val(mi2)){
			hi=mi2;
		}
		else{
			lo=mi1;
		}
	}
	
	cout<<setprecision(12)<<val(lo)<<endl;
}