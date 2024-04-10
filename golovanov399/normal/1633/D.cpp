#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 1011;
int d[N];

void remax(int& x, int y) {
	x = (y > x) ? y : x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> b(n), c(n);
	generate(all(b), nxt);
	generate(all(c), nxt);
	vector<int> res(k + 1);
	for (int i = 0; i < n; ++i) {
		int x = d[b[i]];
		assert(x > -1);
		int y = c[i];
		for (int j = k; j >= x; --j) {
			remax(res[j], res[j - x] + y);
		}
	}
	cout << res[k] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	{
		memset(d, -1, sizeof(d));
		d[1] = 0;
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 1; i <= v; ++i) {
				int x = v + v / i;
				if (x < N && d[x] == -1) {
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
		}
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}