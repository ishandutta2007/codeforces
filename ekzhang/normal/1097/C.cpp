#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
map<int, int> m;
int ans = 0;

pair<int, int> go(string s) {
	int t = 0, x = 0;
	for (char c : s) {
		int b = (c == '(' ? 1 : -1);
		t += b;
		x = min(x, t);
	}
	return { t, x };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		auto p = go(s);
		if (p.first == 0 && p.second == 0) {
			if (m[0])
				++ans, --m[0];
			else
				++m[0];
		}
		if (p.first > 0 && p.second == 0) {
			int x = p.first;
			if (m[x] < 0)
				++ans;
			++m[x];
		}
		if (p.first < 0 && p.second == p.first) {
			int x = -p.first;
			if (m[x] > 0)
				++ans;
			--m[x];
		}
	}

	cout << ans << endl;
	return 0;
}