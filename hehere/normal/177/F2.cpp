#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;

const int maxM = 100;
int n, m, cnt;
int x[maxM], y[maxM], r[maxM];
int p[maxM];
struct State {
	int val;
	int S, T, i;
	State(int v, int S, int T, int i) :
		val(v), S(S), T(T), i(i) {}
	bool operator < (const State &rhs) const {
		return val < rhs.val;
	}
	bool operator > (const State &rhs) const {
		return val > rhs.val;
	}
};
priority_queue< State, vector<State>, std::greater<State> > pq;

bool cmp(int x, int y) {
	return r[x] < r[y];
}

bool extend(int val, int S, int T, int i) {
	if(i < m) {
		int SS = S | (1 << x[p[i]]);
		int TT = T | (1 << y[p[i]]);
		if(SS == S || TT == T) return false;
		pq.emplace(val + r[p[i]], SS, TT, i + 1);
		return true;
	}
	return false;
}

int main() {
	cin >> n >> m >> cnt;
	for(int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i] >> r[i];
		x[i]--; y[i]--;
		p[i] = i;
	}
	std::sort(p, p + m, cmp);
	pq.emplace(0, 0, 0, 0);
	cnt--;
	while(cnt--) {
		auto u = pq.top(); pq.pop();
		int val = u.val, S = u.S, T = u.T, i = u.i;
		for(int j = i; j < m; ++j) extend(val, S, T, j);
	}
	cout << pq.top().val << endl;
	return 0;
}