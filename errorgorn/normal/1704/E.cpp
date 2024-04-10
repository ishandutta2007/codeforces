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

const int MOD=998244353;

int n,m;
int arr[2][1005];
int dp[1005];

vector<int> al[1005];
vector<ii> edges;
bool vis[1005];
int last;

void dfs(int i){
	vis[i]=true;
	
	if (al[i].empty()) dp[i]=1,last=i;
	else dp[i]=0;
	
	for (auto it:al[i]){
		if (!vis[it]) dfs(it);
		dp[i]=(dp[i]+dp[it])%MOD;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		edges.clear();
		
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[0][x];
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) vis[x]=false;
		
		rep(x,0,m){
			int a,b;
			cin>>a>>b;
			edges.pub({a,b});
			al[a].pub(b);
		}
		
		rep(x,1,n+1) if (!vis[x]) dfs(x);
		
		int tot=0;
		rep(x,1,n+1) tot=(tot+arr[0][x]*dp[x])%MOD;
		
		int a=0,b=1;
		int num=0;
		int mx=0;
		rep(x,1,2*n+1){
			rep(y,1,n+1) arr[b][y]=arr[a][y];
			for (auto [u,v]:edges){
				if (arr[a][u]) arr[b][v]++;
			}
			rep(y,1,n+1) if (arr[a][y]) arr[b][y]--;
			if (arr[a][last]){
				num++;
				mx=max(mx,x);
			}
			
			swap(a,b);
			//rep(y,1,n+1) cout<<arr[a][y]<<" "; cout<<endl;
		}
		
		bool fin=true;
		rep(x,1,n+1) if (arr[a][x]) fin=false;
		if (fin) cout<<mx<<endl;
		else cout<<(tot+2*n-num+MOD)%MOD<<endl;
	}
}