#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class FakeIstream {
	inline friend FakeIstream& operator>>(FakeIstream& is, int& val) {
		scanf("%d", &val);
		return is;
	}
} cin;

class FakeOstream {
	inline friend FakeOstream& operator<<(FakeOstream& os, int val) {
		printf("%d", val);
		return os;
	}
	
	inline friend FakeOstream& operator<<(FakeOstream& os, const char* val) {
		printf("%s", val);
		return os;
	}
} cout;

int main() {
	int n; cin >> n;
	vector<int> a(n), p(n), pos(n);
	for (int i = 0; i < n; i++) {
		int val; cin >> val; val--;
		p[val] = i;
	}
	for (int i = 0; i < n; i++) {
		int val; cin >> val; val--;
		a[i] = p[val];
		pos[a[i]] = i;
	}
	int64_t sum = 0;
	vector< pair<int, int> > ans;
	for (int i = 0; i < n; i++) {
		for (int j = pos[i]-1; j >= 0; j--) {
			while (a[i] != i && a[j] >= pos[i]) {
				sum += pos[i] - j;
				ans.emplace_back(pos[i]+1, j+1);
				int pi = pos[i];
				swap(pos[i], pos[a[j]]);
				swap(a[pi], a[j]);
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << sum << "\n";
	cout << ans.size() << "\n";
	for (auto it: ans) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}