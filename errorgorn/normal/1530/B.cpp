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
char grid[20][20];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) rep(y,0,m) grid[x][y]='0';
		grid[0][0]=grid[n-1][0]=grid[0][m-1]=grid[n-1][m-1]='1';
		
		rep(x,1,m-2) if (grid[0][x-1]=='0'){
			grid[0][x]=grid[n-1][x]='1';
		}
		
		rep(x,1,n-2) if (grid[x-1][0]=='0'){
			grid[x][0]=grid[x][m-1]='1';
		}
		
		rep(x,0,n){
			rep(y,0,m) cout<<grid[x][y]; cout<<endl;
		}
		cout<<endl;
		
	}
}