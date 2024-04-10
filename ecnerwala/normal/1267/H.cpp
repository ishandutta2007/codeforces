#include<bits/stdc++.h>
using namespace std;

vector<int> go(vector<int> P) {
	int N = int(P.size());
	vector<int> invP(N);
	for (int i = 0; i < N; i++) invP[P[i]] = i;

	vector<int> res(N);
	vector<set<int>> alive(30);
	vector<set<int, greater<int>>> aliveTimes(30);
	for (int t = 0; t < N; t++) res[t] = 1, alive[res[t]].insert(P[t]), aliveTimes[res[t]].insert(t);

	for (int r = 1; !aliveTimes[r].empty(); r++) {
		for (int t : aliveTimes[r]) {
			int i = P[t];

			auto it = alive[r].find(i);
			if (it == alive[r].end()) continue;
			it = alive[r].erase(it);
			if (it != alive[r].end()) {
				int v = *it;
				res[v] = r+1;
				aliveTimes[res[v]].insert(invP[v]);
				alive[res[v]].insert(v);
				it = alive[r].erase(it);
			}
			if (it != alive[r].begin()) {
				--it;
				int v = *it;
				res[v] = r+1;
				aliveTimes[res[v]].insert(invP[v]);
				alive[res[v]].insert(v);
				it = alive[r].erase(it);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cerr << "Start case" << '\n';
		int N; cin >> N;
		vector<int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> P[i]; P[i] --;
		}
		vector<int> res = go(P);
		for (int i = 0; i < N; i++) {
			cout << res[i] << " \n"[i+1==N];
		}
	}

	return 0;
}