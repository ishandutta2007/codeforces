#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	int S = 0; int probs = 0;
	int cost = 0;
	for (int i = 0; i < N; ++i) {
		S += a[i];
		if (S <= 710)
			++probs;
		else
			break;
		cost += max(0, S - 350);
	}

	cout << probs << " " << cost;
}