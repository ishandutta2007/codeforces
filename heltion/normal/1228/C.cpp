//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
constexpr LL mod = 1000000007;
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
LL h(LL p, LL n){
	if(n < p) return 1;
	return power(p, n / p) * h(p, n / p) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL x, n;
	cin >> x >> n;
	set<LL> sp;
	for(int i = 2; i * i <= x; i += 1)
		for(; x % i == 0; x /= i) sp.insert(i);
	if(x > 1) sp.insert(x);
	LL ans = 1;
	for(LL p : sp)
		ans = ans * h(p, n) % mod;
	cout << ans;
	return 0;
}