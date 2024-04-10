#include <iostream>
#include <map>

using namespace std;

int main() {
	int N;
	map<int, int> S;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int x, y; cin >> x >> y;
		int rez = 0;
		int j;
		for (j = 1; j * j <= x; ++j)
			if (x % j == 0) {
            	if (S.find(j) == S.end() || S[j] < i - y)
					++rez;
				S[j] = i;

				if (S.find(x / j) == S.end() || S[x / j] < i - y)
					++rez;
				S[x / j] = i;
			}

		cout << rez << "\n";
	}
}