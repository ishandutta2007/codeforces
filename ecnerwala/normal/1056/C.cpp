#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 3e3;
const int MAXM = MAXN;
int N, M;
pair<int, int> P[MAXN];
int partner[MAXN];
bool taken[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	N *= 2;
	for (int i = 0; i < N; i++) {
		cin >> P[i].first;
		P[i].second = i;
	}
	for (int i = 0; i < N; i++) {
		partner[i] = -1;
	}
	for (int e = 0; e < M; e++) {
		int a, b; cin >> a >> b;
		a--, b--;
		assert(partner[a] == -1);
		partner[a] = b;
		assert(partner[b] == -1);
		partner[b] = a;

		if (P[a].first > P[b].first) {
			P[a].first = INF;
			P[b].first = -INF;
		} else {
			P[b].first = INF;
			P[a].first = -INF;
		}
	}
	sort(P, P + N);
	reverse(P, P + N);

	int T;
	cin >> T;
	T--;

	int ind = 0;
	int last = -1;
	for (int i = 0; i < N; i++, T ^= 1) {
		if (T == 0) {
			// my turn
			int myMove;
			if (last != -1 && partner[last] != -1 && !taken[partner[last]]) {
				myMove = partner[last];
			} else {
				while (taken[P[ind].second]) ind++;
				myMove = P[ind].second;
			}
			taken[myMove] = true;
			cout << myMove+1 << '\n';
			cout.flush();
		} else if (T == 1) {
			// their turn
			cin >> last;
			last--;
			taken[last] = true;
		} else assert(false);
	}

	return 0;
}