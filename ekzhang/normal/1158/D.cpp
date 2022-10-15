#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> point;
const double PI = 4 * atan(1);

#define MAXN 2013
int N;
point P[MAXN];
string S;
bool vis[MAXN];

LL ccw(point a, point b, point c) {
	return (LL) (b.first - a.first) * (c.second - a.second)
			- (LL) (b.second - a.second) * (c.first - a.first);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i].first >> P[i].second;

	cin >> S;
	S += 'L';

	int cur = 0;
	for (int i = 0; i < N; i++)
		if (P[i] < P[cur])
			cur = i;

	vector<int> ans;
	for (int it = 0; it < N - 1; it++) {
		ans.push_back(cur);
		vis[cur] = true;

		point q = P[cur];
		int x, y;
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				x = y = i;
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				if (ccw(P[i], q, P[x]) > 0)
					x = i;
				if (ccw(P[i], q, P[y]) < 0)
					y = i;
			}
		}

		if (S[it] == 'L')
			cur = y;
		else
			cur = x;
	}

	ans.push_back(cur);
	for (int x : ans)
		cout << x + 1 << ' ';

	cout << endl;
	return 0;
}