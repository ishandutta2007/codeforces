//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int T;
	for(cin >> T; T; T -= 1){
		LL n, s, t;
		cin >> n >> s >> t;
		LL x = s + t - n;
		cout << max(s - x, t - x) + 1 << "\n";
	}
	return 0;
}