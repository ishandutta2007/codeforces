#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	vector<int> a(nxt());
	vector<int> b(nxt());
	generate(all(a), nxt);
	reverse(all(a));
	generate(all(b), nxt);
	set<int> buffer;
	long long ans = 0;
	for (int x : b) {
		if (buffer.count(x)) {
			++ans;
			buffer.erase(x);
		} else {
			while (a.back() != x) {
				buffer.insert(a.back());
				a.pop_back();
			}
			a.pop_back();
			++ans;
			ans += 2 * buffer.size();
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}