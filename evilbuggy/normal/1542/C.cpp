#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

inline long long getCnt(long long n, long long prod){
	return (n/prod)%mod;
}

void solve(){
	long long n; cin >> n;
	long long prod = 1, answer = 0;
	for(int i = 2; ; i++){
		if(prod > n)break;
		long long nprod = (prod/__gcd(i*1LL, prod))*i;
		answer += (getCnt(n, prod) + mod - getCnt(n, nprod))*i%mod;
		prod = nprod;
	}
	answer %= mod;
	if(answer < 0)answer += mod;
	cout << answer << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}