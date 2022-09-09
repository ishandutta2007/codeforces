//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
LL f(LL n){
	if(n % 2 == 0) return f(n / 2) + 1;
	if(n % 3 == 0) return f(n / 3 * 2) + 1;
	if(n % 5 == 0) return f(n / 5 * 4) + 1;
	if(n == 1) return 0;
	return -1e18;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int q;
	for(cin >> q; q; q -= 1){
		LL n;
		cin >> n;
		cout << max(f(n), -1LL) << "\n";
	}
	return 0;
}