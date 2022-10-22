#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	int n, k;
	cin >> n >> k;
	double arr[n];
	double avg, sum;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	avg = 0;
	for (int i = 0; i < k; i++) {
		avg += arr[i]/(n-k+1);
	}
	//cerr << "avg " << 0 << ": " << avg << endl;
	sum = avg;
	for (int i = k; i < n; i++) {
		avg += (arr[i] - arr[i-k])/(n-k+1);
		//cerr << "avg " << i << ": " << avg << endl;
		sum += avg;
	}
	cout << sum << endl;

	return 0;
}