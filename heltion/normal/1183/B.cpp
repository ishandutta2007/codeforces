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
	int q;
	for(cin >> q; q; q -= 1){
		int n, k;
		cin >> n >> k;
		int L = -1e9, R = 1e9;
		for(int i = 1, a; i <= n; i += 1){
			cin >> a;
			L = max(L, a - k);
			R = min(R, a + k);
		}
		if(L > R) cout << "-1\n";
		else cout << R << "\n";
	}
	return 0;
}