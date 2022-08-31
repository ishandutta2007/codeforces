#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N;
int S;
int A[MAXN];
int B[MAXN];

bool go() {
	if (!A[1]) return false;
	if (A[S]) return true;
	assert(!A[S]);
	if (!B[S]) return false;
	for (int i = S+1; i <= N; i++) {
		if (A[i] && B[i]) return true;
	}
	return false;
}

int main() {
	cin >> N >> S;
	assert(S > 1);
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	bool res = go();
	cout << (res ? "YES" : "NO") << '\n';

	return 0;
}