#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int trees, prev, height;
	long long time;
	cin >> trees;
	prev = 0; time = -1;
	for (int i = 0; i < trees; i++) {
		cin >> height;
		time += abs(height-prev)+2;
		prev = height;
	}
	cout << time << endl;
	
	return 0;
}