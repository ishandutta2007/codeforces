#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

pair<int, int> arr[ms];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i-1] = {-a-b-c-d, i}; 
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) {
		if(arr[i].second == 1) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}