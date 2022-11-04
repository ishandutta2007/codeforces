#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, sum, sump;
    cin >> a;
    vector<pair<long long, long long>> arr1;
    for (long long i = 0; i < a; i++) {
	cin >> b;
	sum = 0;
	sump = 0;
	arr1.resize(b);
	for (long long j = 0; j < b; j++) {
	    cin >> arr1[j].first;
	}
	for (int j = 0; j < b; j++) {
	    cin >> arr1[j].second;
	}
	sort(arr1.begin(), arr1.end());
	reverse(arr1.begin(), arr1.end());
	for (long long j = 0; j < b; j++) {
	    if (sump+arr1[j].second < arr1[j].first) {
		sump += arr1[j].second;
		sum = max(sum, sump);
	    } else {
		sum = max(sum, arr1[j].first);
	    }
	}
	cout << sum << "\n";
    }
}