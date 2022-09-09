#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a; 
}
LL dis(LL a, LL b, LL n){
	LL res = b - a;
	if(res < 0) res += n;
	return res;
}
int main(){
	LL n, k, a, b;
	cin >> n >> k >> a >> b;
	LL x = 1, y = n * k;
	for(LL i = 0; i < n; i += 1){
		LL d1 = gcd(n * k, dis(a, i * k + b, n * k));
		LL d2 = gcd(n * k, dis(a, (i + 1) * k - b, n * k));
		x = max(x, max(d1, d2));
		y = min(y, min(d1, d2));
	}
	cout << n * k / x << " " << n * k / y;
}