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

int n;
int arr[200005];
int ans[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		set<int> s;
		rep(x,1,n+1) s.insert(x);
		
		set<int> t=s;
		rep(x,1,n+1) t.erase(arr[x]);
		
		if (sz(t)==1){
			int idx=-1;
			rep(x,1,n+1) if (x!=*t.begin() && arr[x]==arr[*t.begin()]) idx=x;
			if (idx!=-1) arr[idx]=-1;
		}
		
		rep(x,1,n+1) ans[x]=-1;
		vector<int> idx;
		rep(x,1,n+1){
			if (s.count(arr[x])){
				ans[x]=arr[x];
				s.erase(arr[x]);
			}
			else{
				idx.pub(x);
			}
		}
		
		cout<<n-sz(idx)<<endl;
		
		rep(x,1,n+1) if (ans[x]==-1 && s.count(x)){
			ans[x]=x;
			s.erase(x);
		}
		
		rep(x,1,n+1) if (ans[x]==-1){
			ans[x]=*s.begin();
			s.erase(s.begin());
		}
		
		if (sz(idx)) rep(x,0,sz(idx)-1) swap(ans[idx[x]],ans[idx[x+1]]);
		
		rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
	}
	
}