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
string s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>s;
		
		int par=0;
		for (auto it:s) par^=it-'0';
		
		if (par){
			cout<<"-1"<<endl;
			continue;
		}
		
		par=0;
		vector<int> ans;
		rep(x,0,n) if (s[2*x]!=s[2*x+1]){
			rep(y,0,2) if (s[2*x+y]-'0'==par) ans.pub(2*x+y);
			par^=1;
		}
		
		cout<<sz(ans)<<" "; for (auto it:ans) cout<<it+1<<" "; cout<<endl;
		rep(x,0,n) cout<<2*x+1<<" "; cout<<endl;
	}
}