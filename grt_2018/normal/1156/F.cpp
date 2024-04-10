#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int mod = 998244353;
const int nax = 5010;
int n;
int cnt[nax], inv[nax], pref[nax];
int dp[nax][nax];

int fast_pow(int x,int y) {
	int w = 1;
	while(y>0) {
		if(y&1) {
			w = ((LL)w*x)%mod;
		}
		x = ((LL)x*x)%mod;
		y/=2;
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1; i<=n;i++) {
		inv[i] = fast_pow(i,mod-2);
	}
	cnt[0]=1;
	for(int j=n-1; j>=0; j--) {
		for(int i=n; i>=0;i--) {
			if(cnt[i]==0) continue;
			dp[i][j] = (cnt[i]-1+pref[i+1])%mod;
			dp[i][j] = ((LL)dp[i][j] * inv[n-j])%mod;
		}
		for(int i=n;i>=1; i--) {
			pref[i] = ((LL)pref[i+1] + (LL)cnt[i]*dp[i][j])%mod;
		}
	}
	cout<<dp[0][0];
}