#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N, K;
char S[MAXN];

const int INF = 1e9;
struct inds {
	int mi, ma;
	inds() : mi(INF), ma(-INF) {}
	explicit inds(int v) : mi(v), ma(v) {}
	inds(inds a, inds b) : mi(min(a.mi, b.mi)), ma(max(a.ma, b.ma)) {}
	explicit operator bool() const { return mi <= ma; } // non-empty
	int len() const { return max(0, ma - mi + 1); }
};

struct color_inds {
	inds v[2];

	color_inds() {}
	color_inds(int i, int val) { v[val] = inds(i); }
	color_inds(color_inds a, color_inds b) { v[0] = inds(a.v[0], b.v[0]), v[1] = inds(a.v[1], b.v[1]); }

	bool is_done() const { return !v[0] || !v[1]; }
	bool is_winning() const { return min(v[0].len(), v[1].len()) <= K; }
};

color_inds pref[MAXN];
color_inds suff[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K >> S;

	pref[0] = color_inds();
	for (int i = 0; i < N; i++) {
		pref[i+1] = color_inds(pref[i], color_inds(i, S[i] - '0'));
	}
	suff[N] = color_inds();
	for (int i = N-1; i >= 0; i--) {
		suff[i] = color_inds(color_inds(i, S[i] - '0'), suff[i+1]);
	}

	bool isDraw = false;
	for (int i = 0; i+K <= N; i++) {
		for (int z = 0; z < 2; z++) {
			color_inds mid(color_inds(i, z), color_inds(i+K-1, z));
			color_inds all;
			all = color_inds(pref[i], mid);
			all = color_inds(all, suff[i+K]);

			if (all.is_done()) {
				cout << "tokitsukaze" << '\n';
				exit(0);
			} else if (all.is_winning()) {
				// bad move
			} else {
				isDraw = true;
			}
		}
	}

	if (isDraw) {
		cout << "once again" << '\n';
	} else {
		cout << "quailty" << '\n';
	}
	return 0;
}