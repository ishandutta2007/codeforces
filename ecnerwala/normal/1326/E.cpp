#include<bits/stdc++.h>
using namespace std;

const int S = 1 << 19;
struct seg_node {
	int sum = 0;
	int pref = 0;
} seg[2*S];

seg_node merge(const seg_node& a, const seg_node& b) {
	return seg_node{a.sum + b.sum, min(a.pref, a.sum + b.pref)};
}

void updateNode(int i) {
	if (i >= S) {
		seg[i].pref = min(0, seg[i].sum);
	} else {
		seg[i] = merge(seg[2*i], seg[2*i+1]);
	}
}
void updateAll(int i) {
	for (int a = i; a; a /= 2) updateNode(a);
}

seg_node querySuff(int i) {
	seg_node ans{0,0};
	for (int a = S+i, b = 2*S; a < b; a /= 2, b /= 2) {
		if (a & 1) ans = merge(ans, seg[a++]);
		assert(!(b & 1));
	}
	return ans;
}
seg_node queryPref(int i) {
	seg_node ans{0, 0};
	for (int a = S, b = S+i; a < b; a /= 2, b /= 2) {
		assert(!(a&1));
		if (b & 1) ans = merge(seg[--b], ans);
	}
	return ans;
}

bool checkPt(int i) {
	auto lhs = queryPref(i);
	auto rhs = querySuff(i);
	//cerr << lhs.sum << ' ' << lhs.pref << ' ' << rhs.pref << '\n';
	return lhs.sum - lhs.pref + rhs.pref < 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> P(N);
	vector<int> invP(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i]; P[i]--;
		invP[P[i]] = i;
	}

	int curAns = N-1;
	for (int q = 0; q < N; q++) {
		cout << curAns+1 << " ";

		// position x
		int x; cin >> x; x--;

		// mark as a bomb
		seg[S+x].sum--;
		updateAll(S+x);

		if (q+1 == N) {
			break;
		}

		while (checkPt(invP[curAns])) {
			//cerr << q << ' ' << curAns << '\n';
			seg[S+invP[curAns]].sum++;
			updateAll(S+invP[curAns]);
			curAns--;
		}
	}
	cout << '\n';

	return 0;
}