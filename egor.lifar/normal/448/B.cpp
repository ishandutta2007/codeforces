#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s, s1;
map<char, int> m, m1;
bool d[100][100];


int main() {
	cin >> s >> s1;
	if (s.size() < s1.size()) {
		cout << "need tree" << endl;
		return 0;
	}
	bool b = true;
	bool b1 = true;
	for (int j = 0; j < s.size(); j++) {
		m[s[j]]++;
	}
	for (int j = 0; j < s1.size(); j++) {
		m1[s1[j]]++;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		if (m[i] < m1[i]) {
			b = false;
		}
		if (m[i] > m1[i]) {
			b1 = false;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j <= min(i, int(s1.size() - 1)); j++) {
			if (j == 0 && s[i] == s1[j]) {
				d[i][j] = true;
				continue;
			}
			if (j == 0 && i > 0 && d[i - 1][j]) {
				d[i][j] = true;
				continue;
			} 
			if (j == 0 && i == 0) {
				d[i][j] = false;
				continue;
			}
			if (s[i] == s1[j] && d[i - 1][j - 1]) {
				d[i][j] = true;
				continue;
			}
			if (d[i - 1][j]) {
				d[i][j] = true;
				continue;
			}
			d[i][j] = false;
		}
	}
	if (b) {
		if (b1) {
			cout << "array" << endl;
			return 0;
		} else {
			if (d[s.size() - 1][s1.size() - 1]) {
				cout << "automaton" << endl;
			} else {
				cout << "both" << endl;
			}
		}
	} else {
		cout << "need tree" << endl;
	}
	return 0;
}