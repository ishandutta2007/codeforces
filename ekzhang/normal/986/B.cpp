#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int N;
int A[MAXN];
int fen[MAXN];

inline int q(int x) {
	int ret = 0;
	for (; x; x -= x & -x) {
		ret += fen[x];
	}
	return ret;
}

inline void u(int x) {
	for (; x < MAXN; x += x & -x) {
		++fen[x];
	}
}

LL inversions(vector<int> v) {
	memset(fen, 0, sizeof fen);
	LL ans = 0;
	int num = 0;
	for (int x : v) {
		ans += num++ - q(x);
		u(x);
	}
	return ans;
}

inline int r() {
	return rand() ^ (rand() << 16);
}

void bad_shuffle(vector<int>& v, int k) {
	int amt = 0;
	while (amt < k) {
		int a = r() % v.size();
		int b = r() % v.size();
		if (a == b)
			continue;
		++amt;
		swap(v[a], v[b]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	LL k = inversions(v);

	int b = (k%2) ^ (N%2);
	cout << (!b ? "Petr" : "Um_nik") << endl;

	cout.flush();
	return 0;
}