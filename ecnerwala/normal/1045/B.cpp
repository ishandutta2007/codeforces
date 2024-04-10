#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N, M, A0;
int A[MAXN];

int kmp[MAXN];

int match(int cur, int v) {
	if (cur == -1) return 0;
	else if (cur < N && v == A[N-1-cur]) return cur+1;
	else return match(kmp[cur], v);
}

int main() {
	cin >> N;
	cin >> M;
	A[N-1] = M;
	cin >> A0;
	for (int i = 0, prv = A0; i < N-1; i++) {
		int v; cin >> v;
		A[i] = v - prv;
		A[N-1] -= A[i];
		prv = v;
	}
	A0 += A0;
	A0 %= M;

	kmp[0] = -1;
	for (int i = 0; i < N; i++) {
		kmp[i+1] = match(kmp[i], A[N-1-i]);
	}

	int state = 0;
	for (int i = 0; i < N; i++) {
		state = match(state, A[i]);
	}
	vector<int> res;
	for (int i = 0, v = 0; i < N; i++) {
		if (state == N) {
			res.push_back((v + A0) % M);
		}
		state = match(state, A[i]);
		v += A[i];
	}

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i = 0; i < int(res.size()); i++) {
		cout << res[size_t(i)] << " \n"[i+1 == int(res.size())];
	}

	return 0;
}