#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mainHook() {
	int n; cin >> n;
	vector< vector<char> > mat(26, vector<char>(26, 0));
	vector<char> mark(26, false);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char c : s) {
			mark[c - 'a'] = true;
		}
		for (int j = 1; j < (int)s.size(); j++) {
			mat[s[j-1] - 'a'][s[j] - 'a'] = 1;
		}
	}
	
	vector<int> kntIn(26, 0), kntOut(26, 0);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			kntIn[i] += mat[j][i];
			kntOut[i] += mat[i][j];
		}
		if (kntIn[i] > 1 || kntOut[i] > 1) {
			return false;
		}
	}
	
	vector<string> results;
	int checked = 0;
	for (int i = 0; i < 26; i++) {
		if (!mark[i]) {
			checked++;
			continue;
		}
		if (kntIn[i] != 0) {
			continue;
		}
		int qur = i;
		results.emplace_back();
		string &s = results.back();
		s += char(qur + 'a');
		checked++;
		while (kntOut[qur] != 0) {
			for (int j = 0; j < 26; j++) {
				if (mat[qur][j]) {
					qur = j;
					break;
				}
			}
			s += char(qur + 'a');
			checked++;
		}
	}
	
	if (checked != 26) {
		return false;
	}
	
	sort(results.begin(), results.end());
	for (string s : results) {
		cout << s;
	}
	cout << endl;
	
	return true;
}

int main() {
	if (!mainHook()) {
		cout << "NO" << endl;
	}
	return 0;
}