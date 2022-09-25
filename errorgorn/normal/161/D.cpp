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

int n,k;
vector<int> al[50005];
map<int,int> m[50005];

ll ans=0;

void dfs(int i,int p,int d){
	m[i][d]=1;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i,d+1);
		if (sz(m[i])<sz(m[it])) swap(m[i],m[it]);
		
		for (auto &it2:m[it]){
			//a+b==k+d*2
			if (m[i].count(k+d*2-it2.fi)) ans+=m[i][k+d*2-it2.fi]*it2.se;
		}
		for (auto &it2:m[it]){
			m[i][it2.fi]+=it2.se;
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfs(1,-1,0);
	cout<<ans<<endl;
}