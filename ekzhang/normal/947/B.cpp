#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
priority_queue<LL, vector<LL>, greater<LL> > pq;
LL T[MAXN], V[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	LL level = 0;
	for (int i = 0; i < N; i++) {
		LL melt = 0;
		pq.push(V[i] + level);
		while (pq.size() && pq.top() <= level + T[i]) {
			melt += pq.top() - level;
			pq.pop();
		}
		melt += 1LL * pq.size() * T[i];
		level += T[i];
		cout << melt << ' ';
	}

	cout << endl;
	return 0;
}