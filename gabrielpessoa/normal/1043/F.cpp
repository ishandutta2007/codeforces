#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 3e5+5;
const ll mod = 1e9+7;

int a[ms];
int cnt[ms];
ll dp[10][ms];
ll fat[ms];
ll iFat[ms];

ll fExp(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	int hi = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		hi = max(hi, a[i]);
		cnt[a[i]]++;
	}
	fat[0] = 1;
	iFat[0] = 1;
	for(int i = 1; i <= n; i++) {
		fat[i] = fat[i-1] * i % mod;
		iFat[i] = fExp(fat[i], mod - 2);
	}
	cnt[1] = n;
	for(int i = 2; i <= hi; i++) {
		for(int j = i+i; j <= hi; j += i) {
			cnt[i] += cnt[j];
		}
	}
	for(int k = 1; k < 10; k++) {
		for(int i = hi; i > 0; i--) {
			if(cnt[i] < k) continue;
			dp[k][i] = fat[cnt[i]] * iFat[k] % mod * iFat[cnt[i] - k] % mod;
			for(int j = i + i; j <= hi; j += i) {
				dp[k][i] = (dp[k][i] + mod - dp[k][j]) % mod;
			}
		}
		if(dp[k][1]) {
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
}