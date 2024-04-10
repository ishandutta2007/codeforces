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

const int MOD=1000000007;

int n;
vector<int> al[100005];
int bad[100005];

ii dp(int i){
	ii res=ii(1,0);
	
	for (auto &it:al[i]){
		auto temp=dp(it);
		
		res.se=(res.se*(temp.fi+temp.se)+res.fi*temp.se)%MOD;
		res.fi=(res.fi*(temp.fi+temp.se))%MOD;
	}
	
	if (bad[i]) return ii(0,res.fi);
	else return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	rep(x,1,n){
		int t;
		cin>>t;
		
		al[t].push_back(x);
	}
	rep(x,0,n) cin>>bad[x];
	
	cout<<dp(0).se<<endl;
}