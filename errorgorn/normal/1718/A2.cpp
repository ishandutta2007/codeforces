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

int n;
int arr[100005];
int pref[100005];
int ans[100005];
map<int,int> m;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		m.clear();
		
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) pref[x]=pref[x-1]^arr[x];
		
		m[pref[0]]=ans[0];
		rep(x,1,n+1){
			ans[x]=ans[x-1];
			if (m.count(pref[x])) ans[x]=max(ans[x],m[pref[x]]+1);
			m[pref[x]]=ans[x];
		}
		
		cout<<n-ans[n]<<endl;
	}
}