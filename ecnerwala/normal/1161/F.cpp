#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int N;
int A[MAXN][MAXN];

int match[MAXN * 2];

void go() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	cout << "B" << '\n' << flush;

	char incr; cin >> incr;
	if (incr == 'I') {
		// do nothing
	} else if (incr == 'D') {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				A[i][j] *= -1;
			}
		}
	} else assert(false);

	int startNode; cin >> startNode;
	if (startNode > N) {
		// swap it again
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				A[i][j] *= -1;
			}
		}
	}

	// left side wants smaller weights
	// right side wants bigger weights

	for (int i = 1; i <= 2 * N; i++) match[i] = 0;

	vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> pqs(N+1);
	stack<int> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			pqs[i].emplace(A[i][j], j);
		}
		q.push(i);
	}

	while (!q.empty()) {
		int i = q.top(); q.pop();
		assert(!pqs[i].empty());
		int j = pqs[i].top().second; pqs[i].pop();
		if (match[j+N] == 0) {
			match[j+N] = i;
			match[i] = j+N;
		} else if (A[i][j] > A[match[j+N]][j]) {
			int ni = match[j+N];
			match[ni] = 0;
			match[j+N] = i;
			match[i] = j+N;
			q.push(ni);
		} else {
			q.push(i);
		}
	}

	while (true) {
		cout << match[startNode] << '\n' << flush;
		cin >> startNode;
		if (startNode == -1) return;
		if (startNode == -2) exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}