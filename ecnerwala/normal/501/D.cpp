#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int N;

int val[MAXN];

void init() {
	memset(val, 0, sizeof(val));
}

void update(int a) {
	a ++;
	for(int i = a; i <= N; i += i & (-i)) {
		val[i] ++;
	}
}

// query number < a
int query(int a) {
	int res = 0;
	for(int i = a; i > 0; i -= i & (-i)) {
		res += val[i];
	}
	return res;
}

int P[MAXN];

int main() {
	cin >> N;
	memset(P, 0, sizeof(P));
	for(int z = 0; z < 2; z++) {
		init();
		for(int i = 0; i < N; i++) {
			int v; cin >> v;
			P[i] += v - query(v);
			update(v);
		}
	}
	for(int i = N - 1; i >= 0; i--) {
		int mod = N - i;
		if(P[i] >= mod) {
			P[i] -= mod;
			if(i) P[i - 1] ++;
		}
	}

	init();
	for(int i = 0; i < N; i++) {
		int mi = 0, ma = N;
		// want v - query(v) = P[i], v + 1 - query(v + 1) = P[i] + 1;
		// want 
		while(ma - mi > 1) {
			int md = (mi + ma) / 2;
			if(md - query(md) <= P[i]) mi = md;
			else ma = md;
		}
		cout << mi << ' ';
		update(mi);
	}
	cout << '\n';
	return 0;
}