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

ll k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>k;
	
	rep(a,1,2000){
		rep(da,1,2000-a){
			if ((a+k)%da==0 && (a+k)/da+1<=1000000LL*a){
				ll val=(a+k)/da+1;
				
				//cout<<a<<" "<<da<<" "<<val<<endl;
				
				cout<<a+da<<endl;
				
				rep(x,0,da-1) cout<<0<<" ";
				cout<<"-1"<<" ";
				rep(x,0,a){
					cout<<min(val,1000000LL)<<" ";
					val-=min(val,1000000LL);
				}
				
				return 0;
			}
		}
	}
}