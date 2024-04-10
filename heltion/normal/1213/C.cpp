//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		LL n, m;
		cin >> n >> m;
		LL ans = 0, s = 0;
		for(int i = 1; i <= 10; i += 1) s += m * i % 10;
		n = n / m * m;
		ans += n / m / 10 * s;
		for(LL i = n / m / 10 * m * 10 + m; i <= n; i += m) ans += i % 10;
		cout << ans << "\n";
	}
	return 0;
}