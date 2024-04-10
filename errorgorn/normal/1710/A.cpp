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

int n,m,k;
int arr[100005];

bool solve(vector<int> v,int goal){
	vector<int> temp;
	for (auto it:v) if (2<=it) temp.pub(it);
	sort(all(temp));
	
	int l=0,r=0;
	rep(x,0,sz(temp)){
		l+=2,r+=temp[sz(temp)-1-x];
		if (l<=goal && goal<=r) return true;
	}
	return false;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m>>k;
		rep(x,1,k+1) cin>>arr[x];
		
		vector<int> v1,v2;
		rep(x,1,k+1) v1.pub(arr[x]/n),v2.pub(arr[x]/m);
		
		if (solve(v1,m) || solve(v2,n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}