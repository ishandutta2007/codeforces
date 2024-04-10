#include<bits/stdc++.h>
using namespace std;

struct str {
	static const int MAXN = 1.2e5;
	int N;
	char S[MAXN];
	int cntBC[MAXN];
	int cntA[MAXN];

	void read() {
		scanf("%s", S);
		N = int(strlen(S));
	}
	void precompute() {
		cntA[0] = 0;
		cntBC[0] = 0;
		for (int i = 0; i < N; i++) {
			assert('A' <= S[i] && S[i] <= 'C');
			cntBC[i+1] = cntBC[i] + (S[i] != 'A');
			cntA[i+1] = (S[i] == 'A') ? (cntA[i] + 1) : 0;
		}
	}

	// 1-indexed inclusive
	pair<int, int> range(int a, int b) {
		a--;
		return pair<int, int>(cntBC[b] - cntBC[a], min(cntA[b], (b-a)));
	}
};

bool compat(pair<int, int> s, pair<int, int> t) {
	if (s.first > t.first) return false;
	if (s.first % 2 != t.first % 2) return false;
	int AtoBC = (t.first - s.first) / 2;
	if (t.second > s.second) return false;
	if (AtoBC > 0 && t.second < s.second) {
		return true;
	}
	if (AtoBC == 0) {
		assert(t.second <= s.second);
		return (s.second - t.second) % 3 == 0;
	}
	if (t.second == s.second) {
		assert(AtoBC > 0);
		if (s.first > 0) return true;
		else return false;
	}
	assert(false);
	return false;
}

int main() {
	str S, T;
	S.read(), S.precompute();
	T.read(), T.precompute();

	int Q; scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d", int(compat(S.range(a, b), T.range(c, d))));
	}
	printf("\n");

	return 0;
}