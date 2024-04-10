#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,a[1005];
vector<P>vec[1005];
int f[3][3];
ll go[125][125][32];
ll one[125][125][3];
ll dp[125][2];
ll way[1005][4];
ll DP[1005][4];
int main(){
	cin >> n;
	rep(i,n) cin >> a[i];
	cin >> m;
	rep(i,m){
		int x,y,c; cin >> x >> y >> c; x--; c--;
		vec[x].pb(mp(y,c));
	}
	for(int i=0;i<n;i++) vec[i].pb(mp(a[i]+1,-1));
	for(int i=0;i<n;i++) SORT(vec[i]);
	rep(c,3) rep(j,3) cin >> f[c][j];
	rep(c,3){
		for(int i=0;i<64;i++){
			int v[4];
			int x = i;
			rep(j,3) { v[j] = x%4; x /= 4; }
			bool used[5]={};
			rep(j,3) {
				if(f[c][j] == 0) continue;
				used[v[2-j]] = 1;
			}
			rep(i,5) if(!used[i]) {v[3] = i;break;}
			int vv = v[1] + 4*v[2] + 16*v[3];
			go[i][vv][0]++;
			one[i][vv][c]++;
		}
	}
	rep(k,31)rep(ab,64)rep(a,64)rep(b,64){
		go[a][b][k+1] += go[a][ab][k] * go[ab][b][k] % mod;
		if(go[a][b][k+1] >= mod) go[a][b][k+1] -= mod;
	}
	DP[0][0] = 1;
	rep(i,n){
		int C = 0;
		rep(a,64)rep(b,2) dp[a][b] = 0;
		dp[63][0] = 1;
		int cur = 0, nxt = 1;
		rep(j,vec[i].size()){
			int pos = vec[i][j].fi;
			int num = pos-C-1;
			rep(q,31){
				if(!((num>>q)&1)) continue;
				rep(a,64) dp[a][nxt] = 0;
				rep(a,64) rep(b,64){
					dp[b][nxt] += dp[a][cur] * (go[a][b][q]) % mod;
				}
				rep(a,64) dp[a][nxt] %= mod;
				swap(cur,nxt);
			}
			if(j == vec[i].size()-1) break;
			
			{
				rep(a,64) dp[a][nxt] = 0;
				rep(a,64) rep(b,64){
					dp[b][nxt] += dp[a][cur] * (one[a][b][vec[i][j].sc]) % mod;
				}
				rep(a,64) dp[a][nxt] %= mod;
				swap(cur,nxt);
			}
			C = pos;
		}
		rep(a,64){
			if(a/16 >= 4) {assert(dp[a][cur] == 0); continue;}
			way[i][a/16] += dp[a][cur];
			way[i][a/16] %= mod;
		}
		rep(a,4) rep(b,4){
			DP[i+1][b] += DP[i][a] * way[i][a^b] % mod;
			DP[i+1][b] %= mod;
		}
	//	cout << DP[i+1][0] << " " << DP[i+1][1] << " " << DP[i+1][2] << " " << DP[i+1][3] << endl;
	}
	cout << (DP[n][0]+mod)%mod << endl;
}