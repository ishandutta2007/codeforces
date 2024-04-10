#include<bits/stdc++.h>
using namespace std;

// you can win if you can defeat each side of you
// consider the set of values each prefix can take
// WLOG, you're R, then you win unless you're forced to play a P
// order of "goodness" is S > R > P
// R's are useless, cause they can beat rock or scissors, both of which we beat
// if you have a bunch of P's, and any S, then just P's walk over to the nearest S and you win
//
// on each side:
// if you have >= 1 P and only R, you lose
// if you have >= 1 P and >= 1 S, you win
// if you have 0 P, you win
// we'll keep minimal and maximal coordinates, and prefix/suffix counts

const int MAXN = 2.1e5;
int N;
char S[MAXN];
set<int> locs[3];
int bit[3][MAXN];

// update the pt
void update(int b[MAXN], int a, int v) {
	for (a++; a <= MAXN; a += (a & -a)) {
		b[a] += v;
	}
}
// query the prefix sum
int query(int b[MAXN], int a) {
	// number of things < a
	int res = 0;
	for(; a > 0; a -= (a & -a)) {
		res += b[a];
	}
	return res;
}

int typeOf(char c) {
	if (c == 'R') {
		return 0;
	} else if (c == 'P') {
		return 1;
	} else if (c == 'S') {
		return 2;
	} else assert(false);
}

bool isGood(int t, int m) {
	if (m & (1 << ((t+1)%3))) {
		if (m & (1 << ((t+2)%3))) {
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

int lmi[3];
int lma[3];
int getAns() {
	int ans = 0;
	vector<int> cutoffs = {0, N};
	for (int i = 0; i < 3; i++) {
		if (locs[i].empty()) continue;
		lmi[i] = *locs[i].begin();
		lma[i] = *locs[i].rbegin();
		cutoffs.push_back(lmi[i] + 1);
		cutoffs.push_back(lma[i]);
	}
	sort(cutoffs.begin(), cutoffs.end());
	for (int z = 0; z < int(cutoffs.size()) - 1; z++) {
		int lo = cutoffs[z], hi = cutoffs[z+1]; // from [lo, hi)
		assert(lo <= hi);
		if (lo == hi) continue;
		hi--;
		// now it's inclusive
		int lom = 0;
		int him = 0;
		for (int i = 0; i < 3; i++) {
			if (locs[i].empty()) continue;
			if (lmi[i] < lo) {
				lom |= (1 << i);
			}
			if (lma[i] > hi) {
				him |= (1 << i);
			}
		}
		for (int t = 0; t < 3; t++) {
			if (isGood(t, lom) && isGood(t, him)) {
				ans += query(bit[t], hi+1) - query(bit[t], lo);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> N >> Q;
	cin >> S;
	assert(int(strlen(S)) == N);
	for (int i = 0; i < N; i++) {
		int t = typeOf(S[i]);
		locs[t].insert(i);
		update(bit[t], i, +1);
	}
	cout << getAns() << '\n';
	for (int q = 0; q < Q; q++) {
		int ind; char c; cin >> ind >> c;
		ind--;
		int t = typeOf(S[ind]);
		locs[t].erase(ind);
		update(bit[t], ind, -1);

		S[ind] = c;
		t = typeOf(S[ind]);
		locs[t].insert(ind);
		update(bit[t], ind, +1);
		cout << getAns() << '\n';
	}

	return 0;
}