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
string grid[1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		
		vector<int> v1,v2;
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='B'){
			v1.pub(x+y);
			v2.pub(x-y);
		}
		
		sort(all(v1));
		sort(all(v2));
		
		int dist=1e9;
		ii best=ii(-1,-1);
		
		rep(x,0,n) rep(y,0,m){
			int t1=x+y,t2=x-y;
			
			int cost=max({
				abs(t1-v1.front()),
				abs(t1-v1.back()),
				abs(t2-v2.front()),
				abs(t2-v2.back()),
			});
			if (cost<dist){
				dist=cost;
				best={x,y};
			}
		}
		
		cout<<best.fi+1<<" "<<best.se+1<<endl;
	}
}