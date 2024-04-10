// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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
int arr[1000005];
int cnt[5000005];
int dp[5000005];
int res[5000005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,m+1){
			cnt[x]=0;
			dp[x]=m;
			res[x]=0;
		}
		dp[1]=1;
		
		int mn=1e9;
		rep(x,1,n+1){
			cin>>arr[x];
			cnt[arr[x]]++;
			mn=min(mn,arr[x]);
		}
		
		rep(x,1,m+1) if (cnt[x]) res[dp[x]]++;
		
		int curr=m;
		int ans=1e9;
		rep(x,m+1,1){
			if (cnt[x]) res[dp[x]]--;
			dp[x]=x;
			if (cnt[x]) res[dp[x]]++;
			
			if (x<sqrt(m)+5){
				int a=x,b=x*x;
				while (b<=m){
					if (cnt[b]) res[dp[b]]--;
					dp[b]=min(dp[b],max(dp[a],x));
					if (cnt[b]) res[dp[b]]++;
					a++,b+=x;
				}
			}
			
			while (res[curr]==0) curr--;
			if (x<=mn) ans=min(ans,curr-x);
		}
		cout<<ans<<endl;
	}
}