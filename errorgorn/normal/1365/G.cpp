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
vector<int> mask;

ll val[13];

ll test(vector<int> v){
	if (v.empty()) return 0;
	
	cout<<"? "<<sz(v)<<" ";
	for (auto &it:v) cout<<it+1<<" ";
	cout<<endl;
	
	ll res;
	cin>>res;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	rep(x,0,(1<<13)){
		if (__builtin_popcount(x)==6) mask.push_back(x);
	}
	
	rep(bit,0,13){
		vector<int> temp;
		
		rep(x,0,n){
			if (mask[x]&(1<<bit)) temp.push_back(x);
		}
		
		val[bit]=test(temp);
	}
	
	cout<<"! ";
	rep(x,0,n){
		ll curr=0;
		rep(bit,0,13){
			if ((mask[x]&(1<<bit))==0){
				curr|=val[bit];
			}
		}
		
		cout<<curr<<" ";
	}
}