#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	vector<int> p = {0,1,2,3,4,5};
	int a[6];
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
		sum += a[i];
	}
	do {
		int temp = 0;
		for (int i = 0; i < 3; i++) {
			temp += a[p[i]];
		}
		if (2*temp == sum) {
			cout << "YES" << nl;
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << "NO" << nl;

	return 0;
}