#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_set<string> first, second, common;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		first.insert(s);
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (first.find(s) != first.end()) {
			first.erase(s);
			common.insert(s);
		} else {
			second.insert(s);
		}
	}
	int turn = 0;
	while (!common.empty()) {
		turn = 1 - turn;
		common.erase(common.begin());
	}
	while(true) {
		if (turn == 0) {
			if (first.empty()) {
				cout << "NO";
				return 0;
			}
			first.erase(first.begin());
		} else {
			if (second.empty()) {
				cout << "YES";
				return 0;
			}
			second.erase(second.begin());
		}
		turn = 1 - turn;
	}
	return 0;
}