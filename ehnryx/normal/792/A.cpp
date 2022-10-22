#include <bits/stdc++.h>
using namespace std;

int main() {
	int cities;
	cin >> cities;
	vector<int> p;
	int temp;
	for (int i = 0; i < cities; i++) {
		cin >> temp; p.push_back(temp);
	}
	sort(p.begin(), p.end());
	int mind = -1;
	int minnum = 0;
	for (int i = 1; i < cities; i++) {
		if (mind == -1 || abs(p[i]-p[i-1]) < mind) {
			mind = abs(p[i]-p[i-1]);
			minnum = 0;
		}
		if (mind == abs(p[i]-p[i-1])) {
			minnum++;
		}
	}
	cout << mind << " " << minnum << endl;
	return 0;
}