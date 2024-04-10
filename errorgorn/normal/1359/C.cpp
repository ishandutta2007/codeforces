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

long double h,c,t;

long double val(long double i){
	return (c*i+h*(i+1))/(i*2+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>h>>c>>t;
		
		if (t<=(h+c)/2) cout<<2<<endl;
		else{
			ll lo=0,hi=1e18,mi;
			
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (val(mi)>=t) lo=mi;
				else hi=mi;
			}
			
			//cout<<val(0)<<" "<<val(1)<<endl;
			
			if (abs(val(lo)-t)<=abs(val(hi)-t)) cout<<2*lo+1<<endl;
			else cout<<2*hi+1<<endl;
		}
	}
}