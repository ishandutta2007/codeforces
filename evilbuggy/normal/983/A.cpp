#include <bits/stdc++.h>
using namespace std;

inline long long gcd(long long a, long long b){
	while(a != 0){
		b %= a;
		swap(a, b);
	}
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long long p, q, b;
		cin >> p >> q >> b;
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		b = gcd(b, q);
		while(b != 1){
			while(q%b == 0)q /= b;
			b = gcd(b, q);
		}
		if(q == 1)cout << "Finite" << '\n';
		else cout << "Infinite" << '\n';
	}

	return 0;
}