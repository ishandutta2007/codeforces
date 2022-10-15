#include <bits/stdc++.h>
using namespace std;

#define MAXN 100013
int N, M, KA, KB;
int A[MAXN], B[MAXN];
int deg[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> KA >> KB;
	if (KA > M - 1 || KB > N - 1) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < KA; i++)
		cin >> A[i];
	for (int i = 0; i < KB; i++)
		cin >> B[i];

	while (KA < M - 1)
		A[KA++] = 1;
	while (KB < N - 1)
		B[KB++] = N + 1;

	for (int i = 0; i < KA; i++)
		deg[A[i]]++;
	for (int i = 0; i < KB; i++)
		deg[B[i]]++;
	
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= N + M; i++) {
		if (deg[i] == 0)
			pq.push(i);
	}

	int ka = 0, kb = 0;

	cout << "Yes" << '\n';
	for (int i = 0; i < N + M - 2; i++) {
		int x = pq.top();
		pq.pop();
		int y = (x <= N ? B[kb++] : A[ka++]);
		--deg[x];
		--deg[y];
		if (deg[y] == 0)
			pq.push(y);
		cout << x << ' ' << y << '\n';
	}

	int x = pq.top(); pq.pop();
	int y = pq.top(); pq.pop();
	cout << x << ' ' << y << '\n';

	cout.flush();
	return 0;
}