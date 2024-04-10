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

const int nax = 200*1000+10;
int n,g;
pi a[nax];
int dp[nax];
int ans[nax];

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].ST;
		a[i].ND = i;
	}
	sort(a+1,a+1+n);
	for(int i=4; i<=n; i++) {
		dp[i] = max(dp[i-1],dp[max(0,i-3)]+a[i].ST-a[i-1].ST);
	}
	cout<<a[n].ST-a[1].ST-dp[n-2]<<" ";
	g = 1;
	ans[a[n].ND]=ans[a[n-1].ND]=ans[a[n-2].ND]=1;
	for(int i=n-3; i>=1; i--) {
		if(dp[i+1]==dp[i]) {
			ans[a[i].ND]=g;
		} else {
			ans[a[i].ND]=++g;
			ans[a[i-1].ND]=g;
			ans[a[i-2].ND]=g;
			i-=2;
		}
	}
	cout<<g<<"\n";
	for(int i=1; i<=n;i++) cout<<ans[i]<<" ";
	
}