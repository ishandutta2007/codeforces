#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m, k;
	cin >> n >> m >> k;
	if(k == 1){
		cout << "NO" << '\n';
		exit(0);
	}
	long long g1 = __gcd(n, k); n /= g1; k /= g1;
	long long g2 = __gcd(m, k); m /= g2; k /= g2;

	if(k > 2){
		cout << "NO" << '\n';
	}else if(k == 2){
		cout << "YES" << '\n';
		cout << 0 << " " << 0 << '\n';
		cout << n << " " << 0 << '\n';
		cout << 0 << " " << m << '\n';
	}else{
		assert(g1 > 1 || g2 > 1);
		if(g1 > 1){
			n *= 2;
		}else{
			m *= 2;
		}
		cout << "YES" << '\n';
		cout << 0 << " " << 0 << '\n';
		cout << n << " " << 0 << '\n';
		cout << 0 << " " << m << '\n';
	}

	return 0;
}