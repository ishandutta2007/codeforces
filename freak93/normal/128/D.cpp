#include <iostream>
#include <map>

using namespace std;

int main() {
	int N; cin >> N;
	map<int, int> S;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		++S[x];
	}

	if (N % 2) {
		cout << "NO";
		return 0;
	}

	while (S.size() > 0) {
		int x = S.begin() -> first;
		if (S[x] == 0) {
			S.erase(x);
			continue;
		}
		if (S[x + 1] < 2 - (N == 2)) {
			cout << "NO";
			return 0;
		}
		--S[x];
		--S[x + 1];
		N -= 2;
	}

	cout << "YES";
}