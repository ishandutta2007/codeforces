#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
long double prob[N], pref[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(30);

	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	if(m == 1){
		cout << 1.0 << '\n';
		exit(0);
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += x[i];
	}
	prob[0] = 1.0;
	for(int i = 1; i <= sum; i++){
		prob[i] = 0.0;
	}
	for(int i = 0; i < n; i++){
		pref[0] = prob[0];
		for(int j = 1; j <= sum; j++){
			pref[j] = pref[j - 1] + prob[j];
		}
		for(int j = sum; j > 0; j--){
			prob[j] = pref[j - 1];
			if(j > m)prob[j] -= pref[j - m - 1];
			if(j >= x[i])prob[j] -= prob[j - x[i]];
			prob[j] /= (m - 1);
		}
		prob[0] = 0.0;
	}
	long double ans = 0;
	for(int s = 1; s < sum; s++){
		ans += prob[s];
	}
	ans *= (m - 1); ans += 1.0;
	cout << ans << '\n';

	return 0;
}