#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;



int n, k;
string s;
map<char, int> m;
map<char, bool> b;
vector<pair<int, char> > v;
int s1 = 0;



int main() {
	cin >> s;
	n = s.size();
	cin >> k;
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if (m[c] != 0) {
			s1++;
			v.push_back(make_pair(m[c], c));
		}
	}
	sort(v.begin(), v.end());
	int t = 0;
	for (int i = 0; i < v.size(); i++) {
		if (t + v[i].first <= k) {
			t += v[i].first;
			b[v[i].second] = true;
			s1--;
		}
	}
	cout << s1 << endl;
	for (int i = 0; i < n; i++) {
		if (!b[s[i]]) {
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}