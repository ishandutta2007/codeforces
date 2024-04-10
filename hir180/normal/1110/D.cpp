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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int cnt[1000005];
int dp[1000005][5][3];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a); cnt[a]++;
	}
	int ans = 0;
	repn(i,m){
		ans += cnt[i] / 3;
	}
	if(m < 3){
		cout << ans << endl;;
		return 0;
	}
	rep(i,1000005)rep(j,5)rep(k,3) dp[i][j][k] = -INF;
	for(int i=0;i<=2;i++){
		if(cnt[1] < i || cnt[2] < i || cnt[3] < i){
			continue;
		}
		dp[3][i][i] = i;
		int zan = cnt[1]-i;
		dp[3][i][i] += zan / 3;
	}
	for(int i=3;i<m;i++){
		for(int j=0;j<=4;j++){
			for(int k=0;k<=2;k++){
				if(dp[i][j][k] < 0) continue;
				for(int nxt=0;nxt<=2;nxt++){
					if(cnt[i-1]-j-nxt < 0 || cnt[i]-k-nxt < 0 || cnt[i+1]-nxt < 0) continue;
					int add = nxt;
					int zan = cnt[i-1]-j-nxt;
					add += zan / 3;
					dp[i+1][k+nxt][nxt] = max(dp[i+1][k+nxt][nxt],dp[i][j][k]+add);
				}
			}
		}
	}
	for(int j=0;j<=4;j++) for(int k=0;k<=2;k++){
		if(dp[m][j][k] < 0) continue;
		ans = max(ans,dp[m][j][k]+(cnt[m-1]-j)/3+(cnt[m]-k)/3);
	}
	cout<<ans<<endl;
}