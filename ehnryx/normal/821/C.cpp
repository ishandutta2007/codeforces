#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of BAD_STACK:

	int ans = 0;
	int n, ith;
	string command;
	cin >> n;
	int curr = 1;
	stack<int> stk;
	set<int> sorted;
	for (int i = 0; i < 2*n; i++) {
		cin >> command;
		if (command == "add") {
			cin >> ith;
			stk.push(ith);
		}
		else {
			if (stk.empty()) {
				sorted.erase(sorted.begin());
			}
			else {
				if (stk.top() == curr) {
					stk.pop();
				}
				else {
					while (!stk.empty()) {
						sorted.insert(stk.top());
						stk.pop();
					}
					ans++;
					sorted.erase(sorted.begin());
				}
			}
			curr++;
		}
	}
	cout << ans << endl;

The End