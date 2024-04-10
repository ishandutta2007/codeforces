#include <bits/stdc++.h>
using namespace std;
#define MAX 2020202
typedef long long int lld;
vector<lld>odd, even;
int main() {
	lld T;
	cin >> T;
	while (T-- > 0) {
		lld N;
		cin >> N;
		lld i;
		lld ans = 0;
		odd.clear();
		even.clear();
		lld a;
		for (i = 1; i <= N; i++) {
			cin >> a;
			if (a % 2 == 0) even.push_back(a);
			else odd.push_back(a);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		lld p1, p2;
		p1 = p2 = 0;
		while (!(odd.empty() && even.empty())) {
			if (even.empty()) {
				odd.pop_back();
			}
			else if ((odd.empty()) || (odd[odd.size() - 1] < even[even.size() - 1])) {
				p2 += even[even.size() - 1];
				even.pop_back();
			}
			else odd.pop_back();

			if (odd.empty() && even.empty()) break;

			if (odd.empty()) {
				even.pop_back();
			}
			else if ((even.empty()) || (even[even.size() - 1] < odd[odd.size() - 1])) {
				p1 += odd[odd.size() - 1];
				odd.pop_back();
			}
			else even.pop_back();
		}
		if (p1 == p2) cout << "Tie" << endl;
		else if (p1 < p2) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}