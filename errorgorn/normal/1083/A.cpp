/*













*/

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
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
ll w[300005];
vector<ii> al[300005];
ll ans=0;

ll dp(int i,int p){
	vector<ll> children{0,0};
	
	for (auto &it:al[i]){
		if (it.fi==p) continue;
		
		children.push_back(dp(it.fi,i)-it.se);
	}
	
	sort(all(children));
	reverse(all(children));
	
	ans=max(ans,children[0]+children[1]+w[i]);
	
	return max(children[0],0LL)+w[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,1,n+1) cin>>w[x];
	int a,b,c;
	rep(x,1,n){
		cin>>a>>b>>c;
		al[a].push_back(ii(b,c));
		al[b].push_back(ii(a,c));
	}
	
	dp(1,-1);
	
	cout<<ans<<endl;
}