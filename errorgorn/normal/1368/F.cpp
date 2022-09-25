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

int n,k=100;
set<int> s;
set<int> use;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int best=-1;
	rep(x,2,10005){
		if (best<n-(int)ceil((double)n/x)-(x-1)){
			best=n-(int)ceil((double)n/x)-(x-1);
			k=x;
		}
	}
	
	for (int x=n%k;x<=n;x+=k){
		rep(y,1,k) if (x-y>0) s.insert(x-y),use.insert(x-y);
	}
	
	//for (auto &it:s) cout<<it<<" ";
	
	while (sz(s)>(k-1)){
		cout<<k;
		rep(zzz,0,k){
			auto it=s.begin();
			cout<<" "<<*it;
			s.erase(it);
		}
		cout<<endl;
		
		int res;
		cin>>res;
		
		rep(x,0,k){
			if (use.count(res)) s.insert(res);
			
			if (res==n) res=1;
			else res++;
		}
	}
	
	cout<<0<<endl;
}