#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <char> c(n);
		for (int i = 0; i < n; i++)
			cin >> c[i];
		map <pair <int, int>, int> m;
		vector <pair <int, int>> ans;
		int x = 0, y = 0;
		m[{x, y}] = 1;
		for (int i = 0; i < n; i++) {
			if (c[i] == 'U')
				y++;
			if (c[i] == 'D')
				y--;
			if (c[i] == 'L')
				x--;
			if (c[i] == 'R')
				x++;
			if (m[{x, y}] != 0) 
				ans.push_back({ m[{x,y}], i + 2 });
			m[{x, y}] = i + 2;
		}
		pair <int, int> answer;
		if (ans.size() == 0) {
			cout << "-1" << endl;
			continue;
		}
		answer = ans[0];
		for (int i = 1; i < ans.size(); i++)
			if (ans[i].second - ans[i].first < answer.second - answer.first)
				answer = ans[i];
		cout << answer.first << " " << answer.second - 1 << endl;
	}
	return 0;
}