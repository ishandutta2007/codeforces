
// Problem: F. Colouring Game
// Contest: Codeforces - Codeforces Round Testing
// URL: https://codeforces.com/gym/387929/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//
//

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

int g[205];

int get(int i){
	while (i>200) i-=34;
	return g[i];
}

int n;
string s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	g[0]=g[1]=0;
	rep(x,2,205){
		set<int> s;
		rep(y,0,x-1){
			s.insert(g[y]^g[x-y-2]);
		}
		
		while (s.count(g[x])) g[x]++;
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s;
		
		int cnt0=0,cnt1=0;
		for (auto it:s){
			if (it=='B') cnt0++;
			else cnt1++;
		}
		
		int grundy=0;
		int curr=0;
		
		s+=s.back();
		rep(x,0,n){
			if (s[x]==s[x+1]){
				grundy^=get(x-curr+1);
				curr=x+1;
			}
		}
		
		if (cnt0==cnt1){
			if (grundy) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
		else if (cnt0>cnt1) cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
	}
}