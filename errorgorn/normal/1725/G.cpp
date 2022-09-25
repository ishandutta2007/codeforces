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

int pos(int x){
	int res=x;
	if (x>=1) res--;
	if (x>=4) res--;
	res-=(x+2)/4;
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int n;
	cin>>n;
	
	int lo=0,hi=2e9,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (n<=pos(mi)) hi=mi;
		else lo=mi;
	}
	
	cout<<hi<<endl;
	
}