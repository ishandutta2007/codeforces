#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main() {
	int n, i, j;
	cin >> n;
	vi x(n);
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	vii dp(2, vi(n));
	dp[0][n - 1] = 0;
	dp[1][n - 1] = x[n - 1];
	for (i = n - 2; i >= 0; i--) {
		if (dp[1][i + 1] > dp[0][i + 1] + x[i]) {
			dp[1][i] = dp[1][i + 1];
			dp[0][i] = x[i] + dp[0][i + 1];
		}
		else {
			dp[1][i] = x[i] + dp[0][i + 1];
			dp[0][i] = dp[1][i + 1];
		}
	}
	cout << dp[0][0] << " " << dp[1][0] << endl;
}