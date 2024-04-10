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
#define debug(x) cout << #x << " is " << x << endl

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

ll num(ll px1,ll py1,ll px2,ll py2){
	return __gcd(abs(px2-px1),abs(py2-py1));
}

ll num(ll px1,ll py1,ll px2,ll py2,ll px3,ll py3){
	ll b=(num(px1,py1,px2,py2)+num(px1,py1,px3,py3)+num(px2,py2,px3,py3))/2;
	
	ll a=abs(px1*py2+px2*py3+px3*py1-py1*px2+py2*px3+py3*px1)/2;
	
	return abs((a-b+1)%2);
}

int n;
ii arr[6005];

int cnt[2][2];

int val[2][2][2][2][2][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	rep(x,0,n){
		cnt[arr[x].fi%4/2][arr[x].se%4/2]++;
	}
	
	rep(a,0,2) rep(b,0,2) rep(c,0,2) rep(d,0,2) rep(e,0,2) rep(f,0,2){
		val[a][b][c][d][e][f]=num(a*2,b*2,c*2,d*2,e*2,f*2);
	}
	
	ll ans=0;
	
	rep(x,0,n) rep(y,x+1,n) {
		rep(xx,0,2) rep(yy,0,2)
			ans+=cnt[xx][yy]*val[arr[x].fi%4/2][arr[x].se%4/2][arr[y].fi%4/2][arr[y].se%4/2][xx][yy];
		
		ans-=2;
	}
	
	cout<<ans/3<<endl;
}