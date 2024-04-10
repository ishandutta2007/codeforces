//Author: Heltion
//Date: 08-22-2019
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
	int t;
	for(cin >> t; t; t -= 1){
		int b, p, f, h, c, ans = 0;
		cin >> b >> p >> f >> h >> c;
		for(int i = 0; 2 * i <= b and i <= p; i += 1)
			ans = max(ans, h * i + c * min((b - 2 * i) / 2, f));
		cout << ans << "\n";
	}
	return 0;
}