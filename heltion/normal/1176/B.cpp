//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int t;
	for(cin >> t; t; t -= 1){
		int c[3] = {0, 0, 0}, n, a;
		for(cin >> n; n; n -= 1){
			cin >> a;
			c[a % 3] += 1;
		}
		cout << c[0] + min(c[1], c[2]) + abs(c[1] - c[2]) / 3 << "\n";
	}
	return 0;
}