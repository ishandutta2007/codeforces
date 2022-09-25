// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
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

const int MOD=31607;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

int n;
int arr[21][21];
int brr[21][21];

int cnt[21]; //if everything is flipped
int curr[21];
int num[21][21];

int dp[10000000];


void solve(int pos,int mask){
	if (pos==n+2){
		dp[mask]=1;
		rep(x,0,n) dp[mask]=dp[mask]*(MOD+curr[x]-cnt[x])%MOD;
		
		// cout<<mask<<" "<<dp[mask]<<endl;
		// rep(x,0,n) cout<<x<<" "<<curr[x]<<endl;
	}
	else{
		solve(pos+1,mask);
		
		if (pos<n){
			rep(x,0,n){
				num[x][pos]++;
				curr[x]=curr[x]*arr[x][pos]%MOD;
			}
		}
		else if (pos==n){
			rep(x,0,n){
				num[x][x]++;
				if (num[x][x]==1) curr[x]=curr[x]*arr[x][x]%MOD;
			}
		}
		else{
			rep(x,0,n){
				num[x][n-1-x]++;
				if (num[x][n-1-x]==1) curr[x]=curr[x]*arr[x][n-1-x]%MOD;
			}
		}
		
		solve(pos+1,mask|(1<<pos));
		
		if (pos<n){
			rep(x,0,n){
				curr[x]=curr[x]*brr[x][pos]%MOD;
				num[x][pos]--;
			}
		}
		else if (pos==n){
			rep(x,0,n){
				if (num[x][x]==1) curr[x]=curr[x]*brr[x][x]%MOD;
				num[x][x]--;
			}
		}
		else{
			rep(x,0,n){
				if (num[x][n-1-x]==1) curr[x]=curr[x]*brr[x][n-1-x]%MOD;
				num[x][n-1-x]--;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) rep(y,0,n){
		cin>>arr[x][y];
		arr[x][y]=arr[x][y]*inv(10000)%MOD;
		brr[x][y]=inv(arr[x][y]);
	}
	
	rep(x,0,n){
		cnt[x]=1;
		rep(y,0,n) cnt[x]=cnt[x]*arr[x][y]%MOD;
	}
	
	//calculate probability that we lose
	rep(x,0,n) curr[x]=1;
	solve(0,0);
	
	int ans=1;
	rep(x,0,1<<(n+2)){
		if (__builtin_parity(x)) ans=(ans+dp[x])%MOD;
		else ans=(MOD+ans-dp[x])%MOD;
	}
	
	cout<<ans<<endl;
}