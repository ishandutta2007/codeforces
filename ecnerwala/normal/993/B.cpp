#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 20;
int N[2];
pii P[2][MAXN];

int inter(pii a, pii b) {
	if (a == b) return 0;
	if (a.first == b.first) return a.first;
	if (a.first == b.second) return a.first;
	if (a.second == b.first) return a.second;
	if (a.second == b.second) return a.second;
	return 0;
}

int deduce() {
	int poss = -1;
	for (int i = 0; i < N[0]; i++) {
		for (int j = 0; j < N[1]; j++) {
			int cnd = inter(P[0][i], P[1][j]);
			if (cnd == 0) continue;
			if (poss == -1) poss = cnd;
			if (cnd != poss) {
				return 0;
			}
		}
	}
	assert(poss != -1);
	return poss;
}

bool deduce_them() {
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < N[z]; i++) {
			int poss = 0;
			bool good = true;
			for (int j = 0; j < N[!z]; j++) {
				int cnd = inter(P[z][i], P[!z][j]);
				if (cnd == 0) continue;
				if (poss == 0) poss = cnd;
				if (cnd != poss) {
					good = false;
				}
			}
			if (poss == 0) continue; // not possible
			if (good == false) return false;
		}
	}
	return true;
}

int main() {
	cin >> N[0] >> N[1];
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < N[z]; i++) {
			int a, b; cin >> a >> b;
			assert(a != b);
			P[z][i] = pii(min(a,b), max(a,b));
			assert(P[z][i].first < P[z][i].second);
		}
	}

	int res = deduce();
	if (res == 0) {
		// decide if they can deduce uniquely
		if (!deduce_them()) res = -1;
	}
	cout << res << '\n';

	return 0;
}