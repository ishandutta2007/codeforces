#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> indices; // blue
	vector<pair<int,int>> limits; // white
	int next_index = 0;
	vector<int> answer(n);
	
	for(int rep = 0; rep < 2 * n; ++rep) {
		char type;
		cin >> type;
		if(type == '+') {
			// PUT
			indices.push_back(next_index++);
			// limits.emplace_back(1, 1);
			// faster but anyway O(N) version:
			if(!limits.empty() && limits.back().first == 1) {
				limits.back().second++;
			}
			else {
				limits.emplace_back(1, 1);
			}
		}
		else {
			// TAKE
			assert(type == '-');
			int x;
			cin >> x;
			if(limits.empty() || limits.back().first > x) {
				cout << "NO\n";
				return 0;
			}
			assert(!indices.empty());
			answer[indices.back()] = x;
			indices.pop_back();
			limits.back().second--;
			int count = 0;
			while(!limits.empty() && limits.back().first <= x + 1) {
				count += limits.back().second;
				limits.pop_back();
			}
			if(count != 0) {
				limits.emplace_back(x + 1, count);
			}
		}
	}
	cout << "YES\n";
	for(int x : answer) {
		cout << x << " ";
	}
	cout << "\n";
}