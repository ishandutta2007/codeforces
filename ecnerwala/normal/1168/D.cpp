#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
const int MAXQ = 2.1e5;
int N, Q;
int P[MAXN];
char C[MAXN];
vector<int> ch[MAXN];
int depth[MAXN];

int compChild[MAXN];
int compPar[MAXN];
int cnts[MAXN][26];

int subVal[MAXN][26]; // subtree cnts

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;

	P[1] = 0;
	C[1] = '?';
	for (int i = 2; i <= N; i++) {
		cin >> P[i] >> C[i];
	}

	for (int i = 2; i <= N; i++) {
		ch[P[i]].push_back(i);
	}

	depth[1] = 0;
	for (int i = 2; i <= N; i++) {
		depth[i] = depth[P[i]] + 1;
	}

	set<int> leafDepths;
	for (int i = 1; i <= N; i++) {
		if (ch[i].empty()) {
			leafDepths.insert(depth[i]);
		}
	}
	assert(!leafDepths.empty());
	if (leafDepths.size() > 1) {
		for (int q = 0; q < Q; q++) { cout << "Fou" << '\n'; }
		exit(0);
	}

	assert(leafDepths.size() == 1);
	const int leafDepth = *leafDepths.begin();

	// compress the tree
	for (int i = N; i >= 2; i--) {
		compPar[i] = P[i];
		compChild[i] = i;
		if (ch[i].size() == 1) {
			// redirect to ch[i][0]
			compChild[i] = compChild[ch[i][0]];
			compPar[compChild[i]] = P[i];
		}

		if (C[i] != '?') {
			cnts[compChild[i]][C[i] - 'a'] ++;
		}
	}
	compPar[1] = 0;
	compChild[1] = 1;

	for (int i = 1; i <= N; i++) {
		for (auto& c : ch[i]) {
			c = compChild[c];
		}
	}

	int numBad = 0;
	for (int i = N; i >= 1; i--) {
		if (compChild[i] != i) continue;

		for (int v = 0; v < 26; v++) {
			subVal[i][v] = 0;
		}
		for (int j : ch[i]) {
			for (int v = 0; v < 26; v++) {
				subVal[i][v] = max(subVal[i][v], cnts[j][v] + subVal[j][v]);
			}
		}
		int tot = 0;
		for (int v = 0; v < 26; v++) {
			tot += subVal[i][v];
		}
		if (tot + depth[i] > leafDepth) {
			numBad++;
		}
	}

	for (int i = 1; i <= N; i++) {
		//cerr << i << ' ' << compChild[i] << ' ' << compPar[i] << '\n';
	}

	for (int q = 0; q < Q; q++) {
		int i; char c; cin >> i >> c;
		//cerr << i << ' ' << c << '\n';
		if (C[i] != '?') {
			cnts[compChild[i]][C[i] - 'a'] --;
		}
		C[i] = c;
		if (C[i] != '?') {
			cnts[compChild[i]][C[i] - 'a'] ++;
		}
		for (i = compPar[compChild[i]]; i != 0; i = compPar[i]) {
			assert(compChild[i] == i);
			//cerr << "recompute " << i << '\n';
			int tot = 0;
			for (int v = 0; v < 26; v++) tot += subVal[i][v];
			if (tot + depth[i] > leafDepth) {
				numBad --;
			}

			for (int v = 0; v < 26; v++) {
				subVal[i][v] = 0;
			}
			for (int j : ch[i]) {
				for (int v = 0; v < 26; v++) {
					subVal[i][v] = max(subVal[i][v], cnts[j][v] + subVal[j][v]);
				}
			}

			tot = 0;
			for (int v = 0; v < 26; v++) tot += subVal[i][v];
			if (tot + depth[i] > leafDepth) {
				numBad ++;
			}
		}

		if (numBad) {
			cout << "Fou" << '\n';
		} else {
			int tot = 0;
			for (int v = 0; v < 26; v++) {
				tot += subVal[1][v];
			}
			long long res = 0;
			for (int v = 0; v < 26; v++) {
				res += 1ll * ((leafDepth - tot) + subVal[1][v]) * (v+1);
			}
			cout << "Shi" << ' ' << res << '\n';
		}
	}

	return 0;
}