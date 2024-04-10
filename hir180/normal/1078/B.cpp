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
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[105][10005];
bool ok[105][10005];
int n,a[105],cnt[105];
int C[105][105];
bool ch[105][10005];
int S;
int main(){
	for(int i=0;i<105;i++) for(int j=0;j<=i;j++){
		if(j==0 || j==i) C[i][j]=1;
		else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n;
	repn(i,n){
		cin>>a[i];
		cnt[a[i]]++;
		S+=a[i];
	}
	dp[0][0] = 1;
	ok[0][0] = 1;
	repn(i,n){
		for(int j=i-1;j>=0;j--){
			rep(k,10005){
				dp[j+1][k+a[i]] += dp[j][k];
				if(dp[j+1][k+a[i]] >= mod) dp[j+1][k+a[i]] -= mod;
				ok[j+1][k+a[i]] |= ok[j][k];
			}
		}
	}
	int ans = 0;
	repn(i,n) repn(j,10004){
		if(ok[i][j] == 0) continue;
		if(j%i != 0) continue;
		if(j/i > 100) continue;
		if(cnt[j/i] < i) continue;
		if(i*2==n && j*2==S) continue;
		if((dp[i][j]%mod+mod)%mod == (C[cnt[j/i]][i]%mod+mod)%mod){
			ans = max(ans,i);
			ch[i][j] = 1;
		}
	}
	repn(i,n) repn(j,S){
		if(ch[i][j] && ch[n-i][S-j]) ans = n;
	}
	cout<<ans<<endl;
}