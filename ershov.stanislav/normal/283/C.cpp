#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair

const long long mod=1e9+7;

int n, q, t, a[333], used[333], in[333], next[333];
long long dp[111111];

int main() {
	cin >> n >> q >> t;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		next[a]=b;
		in[b]++;
	}
	for (int i=1; i<=n; i++) if (!in[i]) {
		int sum=0;
		for (int v=i; v!=0; v=next[v]) {
			sum+=a[v];
			a[v]=sum;
			if (next[v]) t-=a[v];
			if (t<0) {
				cout << 0; return 0;
			}
			used[v]=1;
		}
	}
	for (int i=1; i<=n; i++) if (!used[i]) {
		cout << 0; return 0;
	}
	dp[0]=1;
	for (int j=1; j<=n; j++) for (int i=a[j]; i<=t; i++) dp[i]=(dp[i]+dp[i-a[j]])%mod;
	if (t>=0) cout << dp[t];
	else cout << 0;
	return 0;
}