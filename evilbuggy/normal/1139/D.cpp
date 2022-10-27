#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 1000000007;

int mu[N], inv[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	inv[1] = 1;
	for(int n = 2; n <= m; n++){
		inv[n] = inv[mod%n]*1LL*(mod - mod/n)%mod;
	}
	memset(mu, 0, sizeof(mu));
	mu[1] = 1;
	for(int n = 1; n <= m; n++){
		for(int i = n + n; i <= m; i += n){
			mu[i] -= mu[n];
		}
	}

	long long answer = inv[m];
	for(int n = 2; n <= m; n++){
		if(!mu[n])continue;
		int c = m/n;
		int tmp = c*1LL*(inv[m - c] + inv[m])%mod;
		answer -= mu[n]*tmp;
	}
	answer %= mod;
	if(answer < 0)answer += mod;
	cout << answer << '\n';

	return 0;
}