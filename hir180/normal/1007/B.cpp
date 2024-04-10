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
int t;
bool used[100005][3];
int dp[3][8][2];
vector<int>D[100005];
bool in[100005];
int main(){
	scanf("%d",&t);
	for(int i=1;i<=100000;i++) for(int j=i;j<=100000;j+=i) D[j].pb(i);
	rep(i,t){
		int a[3]; scanf("%d%d%d",&a[0],&a[1],&a[2]);
		vector<int>vec[3],all; 
		rep(q,3){
			vec[q] = D[a[q]];
			rep(r,vec[q].size()){
				if(!in[vec[q][r]]){
					all.pb(vec[q][r]);
					in[vec[q][r]] = 1;
				}
			}
		}
		rep(q,3){
			for(int i=0;i<vec[q].size();i++) used[vec[q][i]][q] = 1;
		}
		rep(i,3) rep(j,8) rep(k,2) dp[i][j][k] = 0;
		dp[0][0][0] = 1;
		int cur = 0,nxt = 1;
		int ans = 0;
		for(int i=0;i<all.size();i++){
			rep(a,3)rep(b,8) dp[a][b][nxt] = 0;
			if(dp[0][0][cur]){
				dp[0][0][nxt] += dp[0][0][cur];
				//put 1
				int mask=0;
				rep(q,3) if(used[all[i]][q]) mask+=(1<<q);
				dp[1][mask][nxt] += dp[0][0][cur];
				//put 2
				mask=0;
				if(used[all[i]][0] && used[all[i]][1]) mask+=1;
				if(used[all[i]][2] && used[all[i]][1]) mask+=2;
				if(used[all[i]][0] && used[all[i]][2]) mask+=4;
				dp[2][mask][nxt] += dp[0][0][cur];
				//put 3
				if(used[all[i]][0] && used[all[i]][1] && used[all[i]][2]){
					ans+=dp[0][0][cur];
				}
			}
			for(int j=1;j<8;j++){
				if(dp[1][j][cur]){
					dp[1][j][nxt] += dp[1][j][cur];
					//put 1
					int p = ((j>>0)&1);
					int q = ((j>>1)&1);
					int r = ((j>>2)&1);
					int mask = 0;
					if( (p&&used[all[i]][1]) || (q&&used[all[i]][0]) ) mask += 1;
					if( (q&&used[all[i]][2]) || (r&&used[all[i]][1]) ) mask += 2;
					if( (r&&used[all[i]][0]) || (p&&used[all[i]][2]) ) mask += 4;
					dp[2][mask][nxt] += dp[1][j][cur];
					//put 2
					if( (p&&used[all[i]][1]&&used[all[i]][2]) || (q&&used[all[i]][0]&&used[all[i]][2]) || (r&&used[all[i]][1]&&used[all[i]][0]) ){
						ans += dp[1][j][cur];
					}
				}
			}
			for(int j=1;j<8;j++){
				if(dp[2][j][cur]){
					dp[2][j][nxt] += dp[2][j][cur];
					//put 1
					int p = ((j>>0)&1);
					int q = ((j>>1)&1);
					int r = ((j>>2)&1);
					if( (p&&used[all[i]][2]) || (q&&used[all[i]][0]) || (r&&used[all[i]][1]) ){
						ans += dp[2][j][cur];
					}
				}
			}
			swap(cur,nxt);
		}
		printf("%d\n",ans);
		rep(q,3){
			for(int i=0;i<vec[q].size();i++) used[vec[q][i]][q] = 0,in[vec[q][i]] = 0;
		}
	}
}