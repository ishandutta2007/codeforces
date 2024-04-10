#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
const int MAXM = 5.1e5;

int N, M;
bool alive[MAXN * 3];
int E[MAXM][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int e = 0; e < M; e++) {
			cin >> E[e][0] >> E[e][1];
			E[e][0] --, E[e][1] --;
		}
		for (int i = 0; i < 3*N; i++) {
			alive[i] = true;
		}
		vector<int> matching;
		for (int e = 0; e < M; e++) {
			if (alive[E[e][0]] && alive[E[e][1]]) {
				alive[E[e][0]] = false;
				alive[E[e][1]] = false;
				matching.push_back(e);
			}
		}
		vector<int> indSet;
		for (int i = 0; i < 3 * N; i++) {
			if (alive[i]) indSet.push_back(i);
		}
		if (int(matching.size()) >= N) {
			matching.resize(N);
			cout << "Matching" << '\n';
			for (int e : matching) { cout << e+1 << ' '; }
			cout << '\n';
		} else if (int(indSet.size()) >= N) {
			indSet.resize(N);
			cout << "IndSet" << '\n';
			for (int i : indSet) { cout << i+1 << ' '; }
			cout << '\n';
		} else assert(false);
	}

	return 0;
}