//Author: Heltion
//Date: 08-07-2019
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
	LL n, m, q;
	cin >> n >> m >> q;
	LL d = gcd(n, m);
	while(q --){
		LL sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		LL sb, eb;
		if(sx == 1) sb = (sy + n / d - 1) / (n / d);
		else sb = (sy + m / d - 1) / (m / d);
		if(ex == 1) eb = (ey + n / d - 1) / (n / d);
		else eb = (ey + m / d - 1) / (m / d);
		cout << (sb == eb ? "YES\n" : "NO\n");
	}
	return 0;
}