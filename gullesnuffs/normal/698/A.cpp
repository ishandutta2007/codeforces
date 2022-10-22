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

int a[105];
int dp[105][3];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
		if((a[i]&1)){
			dp[i+1][1]=max(dp[i][0], dp[i][2])+1;
		}
		if((a[i]&2)){
			dp[i+1][2]=max(dp[i][0], dp[i][1])+1;
		}
		dp[i+1][0]=max(max(dp[i][0], dp[i][1]), dp[i][2]);
	}
	int i=n;
	dp[i+1][0]=max(max(dp[i][0], dp[i][1]), dp[i][2]);
	printf("%d\n", n-dp[n+1][0]);
}