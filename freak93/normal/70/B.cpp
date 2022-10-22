#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int inf = 0x3f3f3f;
int main() {
	//ifstream cin("input.txt");

	int N;
	cin >> N;

	vector<int> sentence(2, -1);

	string word;
	while (cin >> word) {
		sentence.back() += word.size() + 1;
		char x = word[word.size() - 1];
		if (x == '.' || x == '?' || x == '!')
			sentence.push_back(-1);
	}

	if (sentence.back() < 0)
		sentence.pop_back();
	
	vector<int> dp(sentence.size(), inf);
	dp[0] = 0;
	for (size_t i = 1; i < sentence.size(); ++i) {
		if (sentence[i] > N) {
			cout << "Impossible";
			return 0;
		}
		for (int S = sentence[i], j = i - 1; j >= 0 && S <= N; S += sentence[j] + 1, --j)
			dp[i] = min(dp[i], dp[j] + 1);
	}

	cout << dp[sentence.size() - 1];
}