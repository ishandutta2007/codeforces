#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300*1000+10;
int n,m,k;
int a[nax];
ll dp[nax],p[nax];
ll ans;

int main() {_
	cin>>n>>m>>k;
	for(int i=1; i<=n;i++) {
		cin>>a[i];
		p[i] = p[i-1]+a[i];
	}
	for(int i=m; i<=n;i++) {
		dp[i] = max((ll)0,(ll)(dp[i-m]+p[i]-p[i-m]-k));
	}
	for(int i=0; i<=n; i++) {
		for(int l=1; l<m&&i+l<=n; l++) {
			ans=max(ans,(ll)(dp[i]+p[i+l]-p[i]-k));
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}