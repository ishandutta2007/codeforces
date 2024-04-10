#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
const int mod = 1000000007;

int sum0[N], sum1[N], sum2[N], power2[N + 1], g[N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	memset(sum0, 0, sizeof(sum0));
	memset(sum1, 0, sizeof(sum1));
	memset(sum2, 0, sizeof(sum2));
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		add(sum0[x], 1);
		add(sum1[x], x);
		add(sum2[x], x*1LL*x%mod);
	}
	for(int i = 0, inc = 1; i < 6; i++, inc *= 10){
		for(int mask = N - 1; mask >= 0; mask--){
			if((mask/inc)%10 < 9){
				add(sum0[mask], sum0[mask + inc]);
				add(sum1[mask], sum1[mask + inc]);
				add(sum2[mask], sum2[mask + inc]);
			}
		}
	}
	power2[0] = 1;
	for(int i = 1; i <= n; i++){
		power2[i] = power2[i - 1];
		add(power2[i], power2[i - 1]);
	}
	memset(g, 0, sizeof(g));
	for(int mask = 0; mask < N; mask++){
		if(sum0[mask] == 0)continue;
		if(sum0[mask] == 1){
			g[mask] = sum2[mask];
		}else{
			g[mask] = sum2[mask]*1LL*power2[sum0[mask] - 1]%mod;
			add(g[mask], ((sum1[mask]*1LL*sum1[mask] + mod - sum2[mask])%mod)*power2[sum0[mask] - 2]%mod);
		}
	}
	for(int i = 0, inc = 1; i < 6; i++, inc *= 10){
		for(int mask = 0; mask < N; mask++){
			if((mask/inc)%10 < 9){
				add(g[mask], mod - g[mask + inc]);
			}
		}
	}
	long long answer = 0;
	for(int mask = 0; mask < N; mask++){
		answer ^= mask*1LL*g[mask];
	}
	cout << answer << '\n';

	return 0;
}