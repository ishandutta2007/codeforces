#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long Q; cin >> Q;
	vector<long long> div;

	long long winningMove = 0;
	for (long long i = 2; i * i <= Q; ++i)
		if (Q % i == 0) {
			div.push_back(i);
			if (i != Q / i)
				div.push_back(Q / i);
		}
	div.push_back(Q);

	sort(div.begin(), div.end());
	vector<bool> state(div.size(), false);
	vector<long long> move(div.size(), 0);
	for (size_t i = 0; i < div.size(); ++i) {
		long long win = false;
		long long move2 = true;
		for (size_t j = 0; j < i; ++j)
			if (div[i] % div[j] == 0) {
				move2 = false;
				if (state[j] == false) {
					win = true;
					move[i] = div[j];
				}
			}
		state[i] = win || (move2);
	}

	cout << 2 - static_cast<long long>(state.back()) << "\n";
	if (state.back() == true)
		cout << move.back() << "\n";
}