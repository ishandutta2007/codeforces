#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
double x[N], y[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	double ans = 1e18;
	for(int i = 0; i < n; i++){
		int j = (i - 1 + n)%n;
		int k = (i + 1 + n)%n;
		double a = y[j] - y[k];
		double b = x[k] - x[j];
		double c = -a*x[j] - b*y[j];
		ans = min(ans, abs(a*x[i] + b*y[i] + c)/sqrt(a*a + b*b));
	}
	ans *= 0.5;
	cout << setprecision(30) << ans << '\n';

	return 0;
}