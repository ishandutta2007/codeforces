#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> pt;
#define X real()
#define Y imag()

inline pt rot(pt a) {
	return a * pt(0, 1);
}

inline pt rot(pt a, pt h) {
	return rot(a - h) + h;
}

bool issquare(vector<pt> a) {
	if(a.size() != 4) return false;
	vector<ll> norms;
	for(int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			norms.push_back(norm(a[i] - a[j]));
		}
	}
	sort(norms.begin(), norms.end());
	assert(norms.size() == 6);
	if(norms[0] == 0) return false;
	if(norms[0] == norms[1] && norms[0] == norms[2] && norms[0] == norms[3]
			&& norms[0] * 2 == norms[4] && norms[0] * 2 == norms[5]) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int T; cin >> T;
	for(int t = 0; t < T; t++) {
		vector<pt> A(4), H(4);
		for(int i = 0; i < 4; i++) {
			ll t, u, v, w;
			cin >> t >> u >> v >> w;
			A[i] = pt(t, u);
			H[i] = pt(v, w);
		}
		int best = 10000;
		for(int i = 0; i < 256; i++) {
			vector<pt> cur = A;
			int cost = 0;
			for(int j = 0, v = i; j < 4; j++, v /= 4) {
				for(int k = 0; k < v % 4; k++) {
					cur[j] = rot(cur[j], H[j]);
					cost++;
				}
			}
			if(issquare(cur)) {
				best = min(best, cost);
			}
		}
		if(best > 16) {
			cout << -1 << '\n';
		} else {
			cout << best << '\n';
		}
	}
	return 0;
}