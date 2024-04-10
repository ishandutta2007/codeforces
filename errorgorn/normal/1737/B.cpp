#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'

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

int l,r;

int f(int x){
	int lo=0,hi=1e9+100,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		if (mi*mi<=x) lo=mi;
		else hi=mi;
	}
	
	return 3*(lo-1)+(lo*lo<=x)+(lo*(lo+1)<=x)+(lo*(lo+2)<=x);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	//rep(x,0,10) cout<<x<<" "<<f(x)<<endl;
	
	int TC;
	cin>>TC;
	while (TC--){
		int a,b;
		cin>>a>>b;
		cout<<f(b)-f(a-1)<<endl;
	}
}