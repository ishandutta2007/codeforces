#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int a[1000005];
int dp[1000005];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
	}
	int ans=0;
	rep(i,0,n){
		dp[a[i]]=max(dp[a[i]],1);
		for(int j=2*a[i]; j <= 1000000; j += a[i]){
			dp[j]=max(dp[j],dp[a[i]]+1);
		}
		ans=max(dp[a[i]],ans);
	}
	/*int ans=0;
	rep(i,0,n){
		dp[a[i]]=1;
		rep(j,0,Div[a[i]].size()){
			dp[a[i]]=max(dp[a[i]], dp[Div[a[i]][j]]+1);
		}
		ans=max(ans,dp[a[i]]);
	}*/
	printf("%d\n", ans);
}