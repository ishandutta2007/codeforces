#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector <char> answer;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (answer.size() == 0) {
			answer.push_back(s[i]);
			continue;
		}
		if (answer[answer.size() - 1] == s[i]) {
			answer.pop_back();
			continue;
		}
		answer.push_back(s[i]);
	}
	if (((s.size() - answer.size()) / 2) % 2 == 0)
		cout << "No" << endl;
	else
		cout << "Yes";
	return 0;
}