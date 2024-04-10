#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int BRUTE=1000;

int mex(int a,int b,int c){
	int d=0;
	while (a==d || b==d || c==d) d++;
	return d;
}

int mex(int a,int b){
	int d=0;
	while (a==d || b==d) d++;
	return d;
}

int pos(ll i,int j){
	if (i<BRUTE) return i;
	else return i-((i-BRUTE)/j+1)*j;
}

int n,a,b,c,delta;
ll arr[300005];

int dp[BRUTE][3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>a>>b>>c;
		rep(x,0,n) cin>>arr[x];
		
		dp[0][0]=dp[0][1]=dp[0][2]=0;
		
		rep(x,1,BRUTE){
			dp[x][0]=mex(dp[max(x-a,0)][0],dp[max(x-b,0)][1],dp[max(x-c,0)][2]);
			dp[x][1]=mex(dp[max(x-a,0)][0],dp[max(x-c,0)][2]);
			dp[x][2]=mex(dp[max(x-a,0)][0],dp[max(x-b,0)][1]);
		}
		
		delta=1;
		while (true){
			rep(x,BRUTE,BRUTE-200){
				 rep (y,0,3) if (dp[x][y]!=dp[x-delta][y]){
					delta++;
					goto _end;
				}
			}
			break;
			
			_end:;
		}
		
		//cout<<delta<<endl;
		
		int nim=0;
		rep(x,0,n){
			nim^=dp[pos(arr[x],delta)][0];
		}
		
		int ans=0;
		rep(x,0,n){
			if ((nim^dp[pos(arr[x],delta)][0]^dp[pos(max(arr[x]-a,0LL),delta)][0])==0) ans++;
			if ((nim^dp[pos(arr[x],delta)][0]^dp[pos(max(arr[x]-b,0LL),delta)][1])==0) ans++;
			if ((nim^dp[pos(arr[x],delta)][0]^dp[pos(max(arr[x]-c,0LL),delta)][2])==0) ans++;
		}
		
		cout<<ans<<endl;
	}
	
}