#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int arr[55][55];

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) rep(y,0,m){
			if ((x+y)%2==(x/2+y/2)%2) arr[x][y]=1;
			else arr[x][y]=0;
		}
		rep(x,0,n){
			rep(y,0,m) cout<<arr[x][y]<<" "; cout<<endl;
		}
	}
}