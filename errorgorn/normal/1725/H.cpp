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

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) arr[x]=!!(arr[x]%3);
	
	vector<int> idx;
	rep(x,0,n) idx.pub(x);
	sort(all(idx),[](int i,int j){
		return arr[i]<arr[j];
	});
	
	string ans(n,'1');
	rep(x,0,n/2) ans[idx[x]]='0';
	
	bool low=true;
	rep(x,0,n/2) if (arr[idx[x]]) low=false;
	
	if (low) cout<<2<<endl;
	else cout<<0<<endl;
	cout<<ans<<endl;
}