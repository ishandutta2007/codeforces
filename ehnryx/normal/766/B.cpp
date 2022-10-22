#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	vector<ll> sides;
	ll temp;
	int seg; cin >> seg;
	for (int i = 0; i < seg; i++) {
		cin >> temp; 
		sides.push_back(temp);
	}
	sort(sides.begin(), sides.end());
	for (int i = 2; i < seg; i++) {
		if (sides[i] < sides[i-1] + sides[i-2]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}