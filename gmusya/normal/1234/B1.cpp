#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
	int n, k;
	int timer = 0;
	cin >> n >> k;
	vector <int> answer;
	set <int> s;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		if (s.find(id) != s.end())
			continue;
		answer.push_back(id);
		s.insert(id);
		if (s.size() > k)
			s.erase(answer[answer.size() - k - 1]);
	}
	cout << s.size() << endl;
	for (int i = answer.size() - 1; i >= max(0, (int)answer.size() - k); i--)
		cout << answer[i] << " ";
	return 0;
}