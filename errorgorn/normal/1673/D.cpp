// what the fuck is this problem

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int a,b,c;
int d,e,f;

int solve(int x){
	if (x*b/__gcd(x,b)!=e) return 0;
	
	x=e/x;
	return x*x;
}
		
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>a>>b>>c;
		cin>>d>>e>>f;
		
		tie(a,c)=ii(a,a+(c-1)*b);
		tie(d,f)=ii(d,d+(f-1)*e);
		
		// cout<<a<<" "<<c<<endl;
		// cout<<d<<" "<<f<<endl;
		
		
		if (e%b){
			cout<<0<<endl;
			continue;
		}
		if ((d-a)%b){
			cout<<0<<endl;
			continue;
		}
		if (d<a || c<f){
			cout<<0<<endl;
			continue;
		}
		if (d-e<a || c<f+e){
			cout<<"-1"<<endl;
			continue;
		}
		
		int ans=0;
		for (int x=1;x*x<=e;x++) if (e%x==0){
			ans+=solve(x);
			if (x*x!=e) ans+=solve(e/x);
		}
		
		cout<<ans%1000000007<<endl; //haha very funny
	}
}