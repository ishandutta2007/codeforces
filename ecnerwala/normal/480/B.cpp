#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
int N;
ll L;
ll X, Y;
ll A[MAXN];

inline bool has(ll v) {
	return binary_search(A, A + N, v);
}

void go() {
	bool hx = false, hy = false;
	for(int i = 0; i < N; i++) {
		if(has(A[i] + X)) hx = true;
		if(has(A[i] + Y)) hy = true;
	}

	if(hx && hy) {
		cout << 0 << '\n';
		return;
	} else if(hx) {
		cout << 1 << '\n';
		cout << Y << '\n';
		return;
	} else if(hy) {
		cout << 1 << '\n';
		cout << X << '\n';
		return;
	}
	for(int i = 0; i < N; i++) {
		if(has(A[i] + X + Y)) {
			cout << 1 << '\n';
			cout << A[i] + Y << '\n';
			return;
		}
		if(has(A[i] + Y - X)) {
			if(A[i] + Y <= L) {
				cout << 1 << '\n';
				cout << A[i] + Y << '\n';
				return;
			}
			if(A[i] - X >= 0) {
				cout << 1 << '\n';
				cout << A[i] - X << '\n';
				return;
			}
		}
	}
	cout << 2 << '\n';
	cout << X << ' ' << Y << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> L >> X >> Y;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	go();
	return 0;
}