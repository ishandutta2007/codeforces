/*













*/

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


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
vector<int> al[200005];

ii w[200005][5];

ll ans=0;

void dfs(int i,int p){
	w[i][0].se++;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		
		rep(dx,0,k){
			rep(dy,0,k){
				ans+=w[i][dx].fi*w[it][dy].se
				    +w[it][dx].fi*w[i][dy].se
				    +(int)ceil((double)(dx+dy)/k)*w[i][dx].se*w[it][dy].se;
			}
		}
		
		rep(dx,0,k){
			w[i][dx].fi+=w[it][dx].fi;
			w[i][dx].se+=w[it][dx].se;
		}
	}
	
	rep(x,k-1,0){
		swap(w[i][x],w[i][x+1]);
	}
	
	w[i][0].fi+=w[i][0].se;
	
	//cout<<i<<" ";
	//rep(dx,0,k) cout<<w[i][dx].se<<" ";
	//cout<<endl;
}

int main(){
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
	
	dfs(1,-1);
	
	cout<<ans<<endl;
}