#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p;
	cin >> n >> p;
	vector<long double> prob(n);
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		int cnt = (r/p) - ((l - 1)/p);
		prob[i] = (((long double)cnt)*2000)/(r - l + 1);
	}
	long double ans = 0.0;
	for(int i = 0; i < n; i++){
		ans += 2000 - (2000 - prob[(i + 1)%n])*(2000 - prob[i])/2000;
	}
	cout << fixed << setprecision(30) << ans << endl;

	return 0;
}