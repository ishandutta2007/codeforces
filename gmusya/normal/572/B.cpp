#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	vector <pair <pair <int, int>, char>> answer;
	map <int, int> b, s;
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		char c;
		int val, k;
		cin >> c >> val >> k;
		if (c == 'B')
			b[val] += k;
		if (c == 'S')
			s[val] += k;
	}
	int cnt = 0;
	for (auto hm : s) {
		answer.push_back({ {hm.first, hm.second}, 'S' });
		cnt++;
		if (cnt == d)
			break;
	}
	cnt = 0;
	if (b.size() > 0) 
		for (auto it = --b.end();; --it) {
			auto hm = *it;
			answer.push_back({ {hm.first, hm.second}, 'B' });
			cnt++;
			if (cnt == b.size() || cnt == d)
				break;
		}
	sort(answer.begin(), answer.end());
	reverse(answer.begin(), answer.end());
	for (auto now : answer)
		cout << now.second << " " << now.first.first << " " << now.first.second << endl;
	return 0;
}