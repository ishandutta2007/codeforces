#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int Q, N;
int A[MAXN], F[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			int i, f = 0; cin >> i;
			A[i]++, F[i] += f;
		}

		vector<vector<int> > v(N + 1);
		for (int i = 1; i <= N; i++) {
			v[A[i]].push_back(F[i]);
			A[i] = F[i] = 0;
		}

		priority_queue<int> pq;
		int s = 0, f = 0;
		for (int c = N; c; c--) {
			for (int x : v[c])
				pq.push(x);
			if (pq.size()) {
				s += c, f += min(pq.top(), c);
				pq.pop();
			}
		}

		cout << s << '\n';
	}

	cout.flush();
	return 0;
}