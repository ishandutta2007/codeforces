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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	
	rep(t1,1,10){
		rep(t2,1,10){
			if (t1==t2) continue;
			rep(t3,1,10){
				if (t1==t3 || t2==t3) continue;
				rep(t4,1,10){
					if (t1==t4 || t2==t4 || t3==t4) continue;
					if (t1+t2==a && t3+t4==b && t1+t3==c && t2+t4==d && t1+t4==e && t2+t3==f){
						cout<<t1<<" "<<t2<<endl;
						cout<<t3<<" "<<t4<<endl;
						return 0;
					}
				} 
			}
		}
	}
	
	cout<<"-1"<<endl;
}