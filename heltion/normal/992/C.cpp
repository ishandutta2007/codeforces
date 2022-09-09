#include<bits/stdc++.h> 
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL x, k;
	cin >> x >> k;
	//(x - 1) * 2 ^ (k + 1) + 2 ^ k + 1
	if(not x) cout << 0;
	else cout << ((x - 1) % mod * power(2, k + 1) % mod + power(2, k) + 1) % mod;
	return 0;
}