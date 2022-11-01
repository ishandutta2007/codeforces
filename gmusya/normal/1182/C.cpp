#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define endl '\n'

using namespace std;

bool vowel(char c) {
	return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}

int which(char c) {
	if (c == 'a') return 1;
	if (c == 'o') return 2;
	if (c == 'i') return 3;
	if (c == 'e') return 4;
	if (c == 'u') return 5;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <string> s(n);
	vector <pair <int, int>> a(n);
	unordered_map <int, unordered_map <int, vector <string>>> ms;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = s[i].size() - 1; j >= 0; j--) {
			if (vowel(s[i][j])) {
				a[i].second = which(s[i][j]);
				break;
			}
		}
		for (int j = 0; j < s[i].size(); j++)
			a[i].first += vowel(s[i][j]);
	}
	for (int i = 0; i < n; i++)
		ms[a[i].first][a[i].second].push_back(s[i]);
	vector <pair <string, string>> complete, incomplete;
	int cnt = 0;
	for (auto &number_of_vowels : ms) {
		for (auto &last_vowel : number_of_vowels.second)
			while (last_vowel.second.size() > 1) {
				string s1 = last_vowel.second.back();
				last_vowel.second.pop_back();
				string s2 = last_vowel.second.back();
				last_vowel.second.pop_back();
				complete.push_back({ s1, s2 });
			}
		vector <string> useless;
		for (auto &last_vowel : number_of_vowels.second) {
			for (string &s : last_vowel.second) useless.push_back(s);
			last_vowel.second.clear();
		}
		while (useless.size() >= 2) {
			string s1 = useless.back();
			useless.pop_back();
			string s2 = useless.back();
			useless.pop_back();
			incomplete.push_back({ s1, s2 });
		}
	}
	vector <pair <string, string>> ans;
	while (complete.size() && incomplete.size()) {
		pair <string, string> s1 = incomplete.back();
		incomplete.pop_back();
		pair <string, string> s2 = complete.back();
		complete.pop_back();
		ans.push_back(s1), ans.push_back(s2);
	}
	while (complete.size() > 1) {
		pair <string, string> s1 = complete.back();
		complete.pop_back();
		pair <string, string> s2 = complete.back();
		complete.pop_back();
		ans.push_back(s1), ans.push_back(s2);
	}
	cout << ans.size() / 2 << endl;
	for (int i = 0; i < ans.size(); i += 2)
		cout << ans[i].first << " " << ans[i + 1].first << endl << ans[i].second << " " << ans[i + 1].second << endl;
	return 0;
}