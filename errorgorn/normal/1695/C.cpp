// Super Idol
//    
//  
//    
//  105C
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
int arr[1005][1005];
bitset<2010> bs[1005][1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,n+1) rep(y,1,m+1) cin>>arr[x][y];
		
		bs[1][1].reset();
		bs[1][1][1005]=1;
		rep(x,1,n+1) rep(y,1,m+1){
			if (x+y>2) bs[x][y]=bs[x-1][y]|bs[x][y-1];
			if (arr[x][y]==1) bs[x][y]<<=1;
			else bs[x][y]>>=1;
		}
		
		if (bs[n][m][1005]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}