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
		LL k, n, a, b;
		cin >> k >> n >> a >> b;
		if(n * b >= k) cout << "-1\n";
		else{
			//x * a + b * (n - x) < k
			//(a - b) * x < k - b * n
			cout << min((k - b * n - 1) / (a - b), n) << "\n";
		}
	}
	return 0;
}