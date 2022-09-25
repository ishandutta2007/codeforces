//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

struct UFDS{
	int p[1005];
	int s[1005];
	
	UFDS(){
		rep(x,0,1005){
			p[x]=x;
			s[x]=1;
		}
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	bool unions(int i,int j){
		i=par(i),j=par(j);
		if (i==j) return false;
		
		p[i]=j;
		s[j]+=s[i];
		return true;
	}
} ufds;

int n,m;
ii arr[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,m) cin>>arr[x].fi>>arr[x].se;
	
	int useless=0;
	rep(x,0,m){
		if (!ufds.unions(arr[x].fi,arr[x].se)){
			useless++;
		}
		
		vector<int> cnt;
		rep(x,1,n+1) if (ufds.par(x)==x) cnt.pub(ufds.s[x]);
		
		sort(all(cnt));
		reverse(all(cnt));
		
		//cout<<useless<<endl;
		int ans=-1;
		rep(y,0,useless+1) ans+=cnt[y];
		cout<<ans<<endl;
	}
	
}