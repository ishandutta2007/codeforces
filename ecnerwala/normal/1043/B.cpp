#include<bits/stdc++.h>
using namespace std;

int N;
int A[2000];
int X[2000];

int main() {
	cin >> N;
	A[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		X[i] = A[i+1] - A[i];
	}

	vector<int> res;
	for (int l = 1; l <= N; l++) {
		bool good = true;
		for (int i = 0; i+l < N; i++) {
			if (X[i] != X[i+l]) {
				good = false;
				break;
			}
		}
		if (good) res.push_back(l);
	}
	cout << res.size() << '\n';
	for (int i : res) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}