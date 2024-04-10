#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N, M;
uint64_t H[MAXN];
int outDeg[MAXN];
vector<int> outEdges[MAXN];
vector<int> inEdges[MAXN];

int omegaPow[MAXN];

uint64_t totalNimber[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> H[i];

	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		inEdges[v].push_back(u);
		outEdges[u].push_back(v);
		outDeg[u]++;
	}

	stack<int> q;
	for (int i = 0; i < N; i++) {
		if (outDeg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		assert(outDeg[cur] == 0);

		set<int> nxtOmegas;
		for (int nxt : outEdges[cur]) {
			nxtOmegas.insert(omegaPow[nxt]);
		}
		omegaPow[cur] = 0;
		while (nxtOmegas.count(omegaPow[cur])) omegaPow[cur]++;

		totalNimber[omegaPow[cur]] ^= H[cur];

		for (int prv : inEdges[cur]) {
			if (--outDeg[prv] == 0) {
				q.push(prv);
			}
		}
	}

	bool isZero = true;
	for (int i = 0; i <= N; i++) {
		if (totalNimber[i]) {
			isZero = false;
		}
	}
	if (isZero) {
		cout << "LOSE" << '\n';
		exit(0);
	} else {
		cout << "WIN" << '\n';
		int biggestPow = N+1;
		while (biggestPow >= 0 && totalNimber[biggestPow] == 0) biggestPow--;
		assert(biggestPow != -1);

		int cur;
		for (cur = 0; cur < N; cur++) {
			if (omegaPow[cur] == biggestPow && (totalNimber[omegaPow[cur]] ^ H[cur]) < H[cur]) {
				break;
			}
		}
		assert(cur != N);

		vector<int> nxtOmegas(omegaPow[cur]+1, -1);
		nxtOmegas[omegaPow[cur]] = cur;
		for (int nxt : outEdges[cur]) {
			assert(omegaPow[nxt] != omegaPow[cur]);
			if (omegaPow[nxt] < omegaPow[cur]) {
				nxtOmegas[omegaPow[nxt]] = nxt;
			}
		}
		
		for (int p = 0; p <= omegaPow[cur]; p++) {
			H[nxtOmegas[p]] ^= totalNimber[p];
			totalNimber[p] = 0;
		}
		for (int i = 0; i < N; i++) {
			cout << H[i] << " \n"[i+1==N];
		}
	}

	return 0;
}