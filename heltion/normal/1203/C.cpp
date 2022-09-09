//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, d = 0;
	cin >> n;
	for(LL i = 0, a; i < n; i += 1){
		cin >> a;
		d = gcd(d, a);
	}
	LL ans = 0;
	for(LL i = 1; i * i <= d; i += 1) if(d % i == 0)
		ans += 2 - (i * i == d);
	cout << ans;
	return 0;
}