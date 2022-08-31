#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
const int MAXW = 1e6;

int N;
int A[MAXN];
int W;
int B[MAXW];

int T[MAXW];

void fail() {
	T[0] = -1;
	int pos = 1, cnd = 0;
	while(pos <= W) {
		if(cnd == 0 || B[pos - 1] == B[cnd - 1]) {
			T[pos] = cnd;
			pos++, cnd++;
		} else {
			cnd = T[cnd];
		}
	}
}

int matches() {
	int res = 0;
	int pos = 0;
	int cnd = 0;
	while(pos < N) {
		if(cnd == -1 || (cnd < W && B[cnd] == A[pos])) {
			cnd++, pos++;
			if(cnd == W) res++;
		} else {
			cnd = T[cnd];
		}
	}
	return res;
}

int main() {
	cin >> N >> W;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < W; i++) cin >> B[i];
	if(W == 1) {
		cout << N << '\n';
		return 0;
	}
	N--;
	for(int i = 0; i < N; i++) A[i] -= A[i + 1];
	W--;
	for(int i = 0; i < W; i++) B[i] -= B[i + 1];
	fail();
	cout << matches() << '\n';
	return 0;
}