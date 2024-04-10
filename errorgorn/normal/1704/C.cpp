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

int n,m;
int arr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,m+1) cin>>arr[x];
		sort(arr+1,arr+m+1);
		
		vector<int> v;
		rep(x,1,m) v.pub(arr[x+1]-arr[x]-1);
		v.pub(n-arr[m]+arr[1]-1);
		
		int ans=m;
		sort(all(v)); reverse(all(v));
		//for (auto it:v) cout<<it<<" "; cout<<endl;
		rep(x,0,sz(v)){
			if (v[x]==4*x+1) ans+=4*x;
			else ans+=min(v[x],4*x+1);
		}
		cout<<ans<<endl;
	}
}