#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int A[MAXN];

const int MAXQ = 1.1e5;
int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	bool flip0 = false;

	map<int, int, greater<int>> st;
	for (int q = 0; q < Q; q++) {
		char _c; int x;
		cin >> _c >> x;
		assert(_c == '>' || _c == '<');
		int dir = (_c == '>' ? +1 : -1);
		if (flip0) {
			dir = -dir;
			x = -x;
		}
		if (x * dir < 0) {
			flip0 ^= 1;
			dir = -dir;
		} else {
			x += dir; // first thing that gets flipped
		}
		while (!st.empty() && st.begin()->first >= abs(x)) {
			st.erase(st.begin());
		}
		st.emplace(abs(x), -dir);
	}
	for (int i = 0; i < N; i++) {
		auto it = st.lower_bound(abs(A[i]));
		if (it != st.end()) {
			A[i] = abs(A[i]) * it->second;
		}
		if (flip0) A[i] *= -1;
		cout << A[i] << " \n"[i+1==N];
	}

	return 0;
}