#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string S; cin >> S;
	int N = S.size();

	// put * between characters so we treat even length palindromes easy
	string newS; newS += S[0];
	for (int i = 1; i < N; ++i) {
		newS += "*";
		newS += S[i];
	}
	S = newS;
	N = S.size();

	// palindromes ending and starting at a position

	vector<int> palindromesTo(S.size(), 0);
	vector<int> palindromesFrom(S.size(), 0);
	for (int i = 0; i < N; ++i) {
		int from = i;
		int to = i + 1;
	
		if (i % 2 == 0) {
			palindromesFrom[i]++;
			palindromesTo[i]++;
		}

		while (from > 0 && to < N && S[from - 1] == S[to]) {
			--from;

			if (from % 2 == 0) {
				palindromesFrom[from]++;
				palindromesTo[to]++;
			}
			++to;

			//cerr << "in " << i << " (" << from << ", " << to << ") \n";
		}
	}
	
	for (int i = 1; i < N; ++i)
		palindromesTo[i] += palindromesTo[i - 1];
	long long answer = 0;
	for (int i = 1; i < N; ++i)
		if (i % 2 == 0)
			answer += 1LL * palindromesTo[i - 1] * palindromesFrom[i];

	//for (auto &it: palindromesTo)
	//	cerr << it << " ";
	//cerr << "\n";
	cout << answer << "\n";
}