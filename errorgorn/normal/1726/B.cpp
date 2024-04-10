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

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n,m;
		cin>>n>>m;
		
		if (n>m) cout<<"No"<<endl;
		else if (n%2==0){
			if (m%2==1){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
				int rem=m-n+2;
				rep(x,0,n-2) cout<<1<<" "; cout<<rem/2<<" "<<rem/2<<endl;
			}
		}
		else{
			cout<<"Yes"<<endl;
			rep(x,0,n-1) cout<<1<<" "; cout<<m-n+1<<endl;
		}
	}
}