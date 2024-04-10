// Problem: D1. Zero-One (Easy Version)
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforces.com/contest/1733/problem/D1
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

int n,a,b;
string s,t;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>a>>b;
		cin>>s>>t;
		
		vector<int> pos;
		rep(x,0,n) if (s[x]!=t[x]) pos.pub(x);
		
		if (sz(pos)%2==1){
			cout<<"-1"<<endl;
			continue;
		}
		
		if (a>=b){
			if (sz(pos)==2 && pos[0]+1==pos[1]){
				cout<<min(a,2*b)<<endl;
			}
			else{
				cout<<b*sz(pos)/2<<endl;
			}
		}
		else{
			vector<int> memo={0};
			
			rep(x,0,sz(pos)){
				memo.pub(memo.back()+b);
				if (x) memo.back()=min(memo.back(),memo[x-1]+(pos[x]-pos[x-1])*2*a);
			}
			
			//for (auto it:memo) cout<<it<<" "; cout<<endl;
			
			cout<<memo.back()/2<<endl;
		}
	}
}