#include <bits/stdc++.h>
using namespace std;

inline int mod = 1000*1000*1000 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		long long b; cin >> b;
		long long q; cin >> q;
		long long y; cin >> y;
		
		long long c; cin >> c;
		long long r; cin >> r;
		long long z; cin >> z;

		if(r%q != 0 || (c - b)%q != 0 || c < b || c + (z - 1)*r > b + (y - 1)*q){
			cout << 0 << '\n';
			continue;
		}
		if(c - r < b || c + z*r > b + (y - 1)*q){
			cout << -1 << '\n';
			continue;
		}
		long long ans = 0;
		for(long long p = 1; p*p <= r; p++){
			if(r%p)continue;
			long long k = r/p;
			if(p*q == r*__gcd(p, q)){
				(ans += k*k) %= mod;
			}
			if(p != k && k*q == r*gcd(k, q)){
				(ans += p*p) %= mod;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}