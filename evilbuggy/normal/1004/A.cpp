#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;
	vector<long long> x(n);
	set<long long> possible;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		possible.insert(x[i] - d);
		possible.insert(x[i] + d);
	}
	int ans = 0;
	for(auto y : possible){
		long long mn = 1e18;
		for(auto xx : x){
			mn = min(mn, abs(xx - y));
		}
		if(mn == d)ans++;
	}
	cout << ans << '\n';

	return 0;
}