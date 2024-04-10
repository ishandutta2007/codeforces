#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 303
int N;
int D[MAXN];
vector<pair<int, int> > ans;

void go(int s, int e, int offset) {
	if (s > e)
		return;
	if (s == e) {
		int d = D[s] - offset;
		for (int i = 0; i <= d; i++) {
			for (int j = i + 1; j <= d; j++) {
				ans.emplace_back(i, j);
			}
		}
		return;
	}
	int ds = D[s] - offset;
	int de = D[e] - offset;
	for (int i = de; i > de - ds; i--) {
		for (int j = 0; j < i; j++) {
			ans.emplace_back(i, j);
		}
	}
	go(s + 1, e - 1, offset + ds);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> D[i];

	go(0, N - 1, 0);

	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
	cout.flush();
	return 0;
}