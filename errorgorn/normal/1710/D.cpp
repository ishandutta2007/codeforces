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
bool has[2005][2005];
vector<ii> edges;

void solve(int l,int r){
	if (l==r) return;
	
	int R=r-1;
	while (!has[l][R]) R--;
	
	solve(l,R);
	
	int curr=R+1;
	vector<int> v;
	while (curr<=r){
		int R=r;
		while (!has[curr][R]) R--;
		solve(curr,R);
		v.pub(R);
		curr=R+1;
	}
	
	int L=R;
	while (!has[L][r]) L--;
	
	if (sz(v)==1){
		edges.pub({L,v[0]});
	}
	else{
		int ss=sz(v)-1;
		rep(x,0,ss-1) edges.pub({v[ss],v[x]});
		edges.pub({L,v[ss-1]});
		edges.pub({L,v[ss]});
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,1,n+1) rep(y,x,n+1) has[x][y]=false;
		
		string s;
		rep(x,1,n+1){
			cin>>s;
			rep(y,0,n+1-x) has[x][x+y]=s[y]-'0';
		}
		
		edges.clear();
		
		solve(1,n);
		
		for (auto [a,b]:edges){
			cout<<a<<" "<<b<<endl;
		}
	}
	
}