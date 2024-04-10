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

int a[40005];
int dp[32005][305];
int dp2[32005][305];
map<int, int> M;

int main(){
	int n, T;
	scanf("%d%d", &n, &T);
	rep(i,0,n){
		scanf("%d", a+i);
		++M[a[i]];
	}
	rep(i,n,30205){
		a[i]=a[i-n];
	}
	int ans=0;
	rep(i,0,min(n*T, 30205)){
		rep(j,0,305){
			dp[i+1][j]=dp[i][j];
			if(j && dp[i+1][j-1] > dp[i+1][j])
				dp[i+1][j]=max(dp[i+1][j], dp[i+1][j-1]);
			if(a[i] == j)
				dp[i+1][j]=max(dp[i+1][j], dp[i][j]+1);
			ans=max(ans, dp[i+1][j]);
		}
	}
	if(n*T > 22000){
	int jump=((n*T-12000)/n)*n;
	ll base=((10100)/n)*n;
	rep(i,jump,n*T){
		/*if(i == n*T-1){
			printf("a");
		}*/
		rep(j,0,305){
			int k=base+(i%n);
			dp2[i+1-jump][j]=dp[k+1][j]+M[j]*((i-k)/n);
			dp2[i+1-jump][j]=max(dp2[i+1-jump][j], dp2[i-jump][j]);
			if(j && dp2[i+1-jump][j-1] > dp2[i+1-jump][j])
				dp2[i+1-jump][j]=dp2[i+1-jump][j-1];
			if(a[i%n] == j)
				dp2[i+1-jump][j]=max(dp2[i+1-jump][j], dp2[i-jump][j]+1);
			ans=max(ans, dp2[i+1-jump][j]);
		}
	}
	}
	printf("%d\n", ans);
}