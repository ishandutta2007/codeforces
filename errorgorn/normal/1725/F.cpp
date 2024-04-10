//
//
//
//

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
ii arr[100005];
int ans[30];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	rep(bit,0,30){
		vector<ii> upd;
		rep(x,0,n){
			if (arr[x].se-arr[x].fi+1>=(1<<bit)) upd.pub({0,1});
			else{
				int a=arr[x].fi%(1<<bit),b=arr[x].se%(1<<bit);
				upd.pub({a,1}),upd.pub({b+1,-1});
				if (a>b) upd.pub({0,1});
			}
		}
		
		int best=0;
		int curr=0;
		sort(all(upd));
		for (auto [a,b]:upd){
			curr+=b;
			best=max(best,curr);
		}
		
		ans[bit]=best;
	}
	
	cin>>q;
	int a;
	while (q--){
		cin>>a;
		cout<<ans[__builtin_ctz(a)]<<endl;
	}
}