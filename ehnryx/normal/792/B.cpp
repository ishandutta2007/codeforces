#include <bits/stdc++.h>
using namespace std;

int main() {
	int num, steps, com;
	cin >> num >> steps;

	vector<int> p;
	for (int i = 1; i <= num; i++)
		p.push_back(i);
	int curr = 0;
	while (steps--) {
		cin >> com;
		curr = (curr+com) % p.size();
		cout << p[curr] << " ";
		p.erase(p.begin()+curr);
	}
	cout << endl;

	return 0;
}