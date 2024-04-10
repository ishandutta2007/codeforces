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

int n,q;
int arr[100005];
vector<int> win[100005];
deque<int> qu;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		rep(x,1,n+1) cin>>arr[x];
		
		rep(x,1,n+1) win[x].clear();
		
		qu.clear();
		rep(x,1,n+1) qu.pub(x);
		
		rep(x,1,n+1){
			int a=qu.front(); qu.pof();
			int b=qu.front(); qu.pof();
			
			if (arr[a]>arr[b]){
				qu.puf(a);
				qu.pub(b);
				win[a].pub(x);
			}
			else{
				qu.puf(b);
				qu.pub(a);
				win[b].pub(x);
			}
		}
		
		int a,b;
		while (q--){
			cin>>a>>b;
			int ans=ub(all(win[a]),b)-win[a].begin();
			if (n<b && arr[a]==n) ans+=b-n;
			cout<<ans<<endl;
		}
	}
}