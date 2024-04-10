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

int n;
ii ans[500005];

int prime[10000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,2,3200) if (prime[x]==0){
		for (int y=x*2;y<10000005;y+=x) prime[y]=x;
	}
	
	cin>>n;
	
	rep(x,0,n){
		int t;
		cin>>t;
		
		int p=prime[t];
		
		if (prime[t]==0){
			ans[x]=ii(-1,-1);
		}
		else{
			while(t%p==0) t/=p;
			
			if (t==1) ans[x]=ii(-1,-1);
			else ans[x]=ii(p,t);
		}
	}
	
	rep(x,0,n) cout<<ans[x].fi<<" ";
	cout<<endl;
	rep(x,0,n) cout<<ans[x].se<<" ";
	cout<<endl;
}