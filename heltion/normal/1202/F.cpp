//Author: Heltion
//Date: 08-07-2019
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
	LL a, b, n, ans = 0;
	cin >> a >> b;
	n = a + b;
	for(LL i = 1, L, R; ; i = n / (L - 1)){
		L = n / (i + 1) + 1, R = n / i;
		//x * i <= a <= x * (i + 1)
		//y * i <= b <= y * (i + 1) 

		LL xR = a / i, xL = (a + i) / (i + 1);
		LL yR = b / i, yL = (b + i) / (i + 1);

		LL cL = max(xL + yL, L), cR = min(xR + yR, R);

		if(xL <= xR and yL <= yR) ans += max(0LL, cR - cL + 1);

		//cout << i << " " << L << " " << R << "\n";
		//cout << xL << " " << xR << " " << yL << " " << yR << "\n";
		//cout << cL << " " << cR << "\n";

		if(L == 1) break;
	}
	cout << ans;
	return 0;
}